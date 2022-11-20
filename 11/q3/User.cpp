#include "User.h"
#include "USocial.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>

User::User() {}

User::~User() {
	// Release posts
	for (auto p : posts) {
		delete p;
	}

	// Release messages
	for (auto m : receivedMsgs) {
		delete m;
	}
}

unsigned long User::getId()
{
	return id;
}

std::string User::getName()
{
	return name;
}

void User::addFriend(User* new_friend)
{
	if (new_friend == nullptr) {
		throw std::invalid_argument("The new friend cannot be null!");
	}

	if (new_friend == this) {
		throw std::invalid_argument("User can't be a friend of himself!");
	}

	if (areFriends(new_friend)) {
		throw std::invalid_argument("The new friend to add and this user are already friends.");
	}

	friends.push_back(new_friend->id);
}

void User::removeFriend(User* to_remove)
{
	if (to_remove == nullptr) {
		throw std::invalid_argument("Friend to remove cannot be null!");
	}

	if (!areFriends(to_remove)) {
		throw std::invalid_argument("Cannot remove someone who isn't a friend, from the friend list!");
	}

	friends.remove(to_remove->id);
}

void User::post(std::string text)
{
	posts.push_back(new Post(text));
}

void User::post(std::string text, Media* media)
{
	posts.push_back(new Post(text, media));
}

std::list<Post*> User::getPosts()
{
	return posts;
}

void User::viewFriendsPosts()
{
	for (auto friendId : friends) {
		auto u = us->getUserById(friendId);
		u->viewPosts();
	}
}

void User::receieveMessage(Message* incoming)
{
	if (incoming == nullptr) {
		throw std::invalid_argument("Incoming message must not be null!");
	}

	receivedMsgs.push_back(incoming);
}

void User::sendMessage(User* dest, Message* outgoing)
{
	if (dest == nullptr) {
		throw std::invalid_argument("Destination user cannot be null!");
	}
	if (outgoing == nullptr) {
		throw std::invalid_argument("Message to send cannot be null!");
	}

	if (!areFriends(dest)) {
		throw std::invalid_argument("Regular user cannot send a message to a non-friend user.");
	}

	dest->receieveMessage(outgoing);
}

void User::viewReceivedMessages()
{
	for (auto msg : receivedMsgs) {
		std::cout << "Received Message: ";
		std::cout << msg->getText() << std::endl;
	}
}

void User::viewPosts() {
	for (auto post : posts) {

		// Post header
		std::cout << name << " posted: \n";
		// Post text
		std::cout << post->getText() << std::endl;

		// Post media
		if (post->getMedia() != nullptr) {
			post->getMedia()->display();
		}

		std::cout << std::endl;
	}
}

bool User::areFriends(User* to_check) {
	return std::find(friends.begin(), friends.end(), to_check->id) != friends.end();
}
