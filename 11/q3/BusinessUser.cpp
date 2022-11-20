#include "BusinessUser.h"
#include <stdexcept>

void BusinessUser::sendMessage(User* dest, Message* outgoing)
{
	if (dest == nullptr or outgoing == nullptr) {
		throw std::invalid_argument("Destionation user and outgoing message must both not be null!");
	}

	if (dest == this) {
		throw std::invalid_argument("User cannot send a message to himself!");
	}

	dest->receieveMessage(outgoing);
}
