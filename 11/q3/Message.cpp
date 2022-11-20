#include "Message.h"
#include <stdexcept>
#include <algorithm>

Message::Message(std::string text)
{
	if (text.empty() or std::all_of(text.begin(), text.end(), isspace)) {
		throw std::invalid_argument("Message cannot be empty or white space!");
	}
	this->text = text;
}

std::string Message::getText()
{
	return text;
}
