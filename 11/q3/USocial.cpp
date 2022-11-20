#include "USocial.h"
#include "User.h"
#include "BusinessUser.h"
#include <algorithm>
#include <stdexcept>


USocial::~USocial()
{
	// clear allocated users from registerUser
	for (auto u : users) {
		delete u.second;
	}
}

User* USocial::getUserById(unsigned long userId) {
	if (!userInMap(userId)) {
		throw std::invalid_argument("User with the specified id doesn't exist!");
	}
	return users.at(userId);
}

User* USocial::registerUser(std::string name, bool is_business)
{
	if (name.empty() or std::all_of(name.begin(), name.end(), isspace)) {
		throw std::invalid_argument("User name cannot be empty or white space!");
	}

	User* u;
	// Switch regular & business users.
	if (is_business) {
		u = new BusinessUser();
	}
	else {
		u = new User();
	}
	u->id = next_id++;
	u->name = name;
	u->us = this;
	users[u->id] = u;
	return u;
}

void USocial::removeUser(User* to_remove)
{
	if (to_remove == nullptr)
		throw std::invalid_argument("User to remove cannot be null!");
	if (!userInMap(to_remove->id))
		throw std::invalid_argument("Cannot remove a non-existing user!");

	// remove from main user collection
	users.erase(to_remove->id);

	// remove friends of the removed user
	for (auto u : users) {
		try {
			u.second->removeFriend(to_remove);
		}
		catch (std::invalid_argument) {};
	}

	delete to_remove;
}

bool USocial::userInMap(unsigned long userId) {
	return users.find(userId) != users.end();
}