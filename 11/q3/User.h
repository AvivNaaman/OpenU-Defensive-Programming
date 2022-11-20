#pragma once
#include "Post.h"
#include <list>
#include "Message.h"

class User
{
	friend class USocial;

protected:
	USocial* us;
	unsigned long id;
	std::string name;
	std::list<unsigned long> friends;
	std::list<Post*> posts;
	std::list<Message*> receivedMsgs;
	User();
	~User();

public:
	unsigned long getId();
	std::string getName();
	void addFriend(User*);
	void removeFriend(User*);
	void post(std::string);
	void post(std::string, Media*);
	std::list<Post*> getPosts();
	void viewFriendsPosts();
	void receieveMessage(Message*);
	virtual void sendMessage(User*, Message*);
	void viewReceivedMessages();
	void viewPosts();
private:
	bool areFriends(User*);
};

