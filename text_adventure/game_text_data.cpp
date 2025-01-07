#include <unordered_map>
#include "GameText.h"

const std::unordered_map<std::string, slowly_printing_string> story_text{
  {"setting", slowly_printing_string{ "You wake up in a dense, eerie forest.\nThe air is thick with mist, and you have no memory of how you got here.\nA faint voice calls your name, echoing through the trees.\nYou must navigate the forest and uncover its secrets while deciding whether to trust the voice.\n", 35 }},
  {"beginning", slowly_printing_string{ "You hear a voice whisper:\n \"Come to me, and you will be free.\"\n", 15}}
};