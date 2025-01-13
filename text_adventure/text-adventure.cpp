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
#include <termios.h>
#include <unistd.h>
#include "GameText.h"

// Function prototypes
void disableRawMode(); 
void enableRawMode();


struct termios orig_termios;

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

    enableRawMode();

    char buffer[3]; // Buffer to hold up to 3 bytes (ESC, [, A)
    while(read(STDIN_FILENO, &buffer[0], 1) == 1 && buffer[0] != 'q') {
        if (buffer[0] == '\033') { // Check if beginning of an escape sequence 
            if (read(STDIN_FILENO, &buffer[1], 2) == 2) { // Check if 2 remaining bytes
                if (buffer[1] == '[' && buffer[2] == 'A') { // Check if next 2 bytes match up arrow escape sequence
                    std::cout << "You pressed the up arrow\n";
                }
            }
        }
    }

    return 0;
}

// Function definitions
void disableRawMode() { // Idea from https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
} 

void enableRawMode() { // From above link
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON); // Turn off input echo in terminal

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
