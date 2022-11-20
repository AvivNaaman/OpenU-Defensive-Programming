#pragma once

#include <string>
#include "Media.h"

class Post {
    std::string text;
    Media *media;
    
public:
    Post(std::string text);
    Post(std::string text, Media *media);
    std::string getText();
    Media *getMedia();
};

