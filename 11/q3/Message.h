#pragma once
#include <string>

class Message
{
	std::string text;

public:
	Message(std::string);
	std::string getText();
};

