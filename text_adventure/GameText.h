#ifndef GAME_TEXT
#define GAME_TEXT

#include <unordered_map>
#include <string>

struct slowly_printing_string { 
    std::string data; 
    long int delay; 
};

extern const std::unordered_map<std::string, slowly_printing_string> story_text;

#endif