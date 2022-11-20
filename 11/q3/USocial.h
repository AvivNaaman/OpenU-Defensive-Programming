#pragma once

#include <string>
#include <map>
#include "User.h"

class USocial
{
	std::map<unsigned long, User*> users;
	unsigned int next_id = 1;

public:
	~USocial();
	User* registerUser(std::string name, bool is_business = false);
	void removeUser(User*);
	User* getUserById(unsigned long);

private:
	bool userInMap(unsigned long userId);
};

