/* 
** Choose your own adventure project **
This contains a beginning and 3 possible endings



Story map:
                      Start
                        |
        ---------------------------------
        |               |               |
  Lighted Path      Riverbank       Dark Tunnel
        |               |               |
    Touch or         Trust or        Follow or
    Ignore           Refuse          Refuse
        |               |               |
    Ending 1/2       Ending 3/4     Ending 5/6
*/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <unordered_map>
#include "GameText.h"

// Slow print string idea from https://wandbox.org/permlink/OAbOpSLiAeJRRfbI
std::ostream& operator<<(std::ostream& out, const slowly_printing_string& s) {
    for (const auto& c : s.data) {
        out << c << std::flush;        
        std::this_thread::sleep_for(std::chrono::milliseconds(s.delay));
    }
    return out;
}

int main() {
  const std::string textSeparator = "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";

  std::cout << story_text.at("setting");
  std::cout << story_text.at("beginning");
  std::cout << textSeparator;
  return 0;
}