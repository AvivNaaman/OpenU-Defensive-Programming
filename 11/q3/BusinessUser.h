#pragma once
#include "User.h"

class BusinessUser : public User
{
public:
	virtual void sendMessage(User*, Message*);
};

