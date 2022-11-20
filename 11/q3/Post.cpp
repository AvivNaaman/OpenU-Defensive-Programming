#include "Post.h"
#include <iostream>
#include <algorithm>

Post::Post(std::string text): Post(text, nullptr) {  }

Post::Post(std::string text, Media* media) {
	if (media == nullptr and (text.empty() or std::all_of(text.begin(), text.end(), isspace))) {
		throw std::invalid_argument("Post text cannot be empty or white space without media!");
	}
	this->text = text;
	this->media = media;
}

std::string Post::getText()
{
	return text;
}

Media* Post::getMedia()
{
	return media;
}


