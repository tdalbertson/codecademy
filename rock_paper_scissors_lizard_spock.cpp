/*
Rock, Paper, Scissors, Lizard, Spock
Explanation:
Originally from The Big Bang Theory, this is Rock, Paper, Scissors with 2 additional options: Lizard & Spock.

Rules:
1. Rock:
  - Crushes Scissors
  - Crushes Lizard
2. Paper:
  - Covers Rock
  - Disproves Spock
3. Scissors:
  - Cuts Paper
  - Decapitates Lizard
4. Lizard:
  - Eats Paper
  - Poisons Spock
5. Spock:
  - Smashes Scissors
  - Vaporizes Rock

Flow:
- Prompt the User to enter one of the options: Get User Choice
  **Ensure that incorrect input is handled
- Generate a random choice for the Computer: Get Computer Choice
- Compare & evaluate the User's choice versus Computer's random choice
- Display results and keep score
- Repeat until either the User or the Computer earns 5 points and display the winner
**Draws are not counted**
*/

#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <random>

// Function Prototypes
std::string getUserChoice(); 
std::string getComputerChoice();
bool checkUserChoice(std::string choice);
void makeLower(std::string& word);
bool compareChoices(const std::string& uChoice, const std::string& cChoice, bool& tieFlag);

// List of all defeats for each option - Move: Defeats
const std::map<std::string, std::array<std::string, 2>> defeats {
  {"rock", {"scissors", "lizard"}},
  {"paper", {"rock", "spock"}},
  {"scissors", {"paper", "lizard"}},
  {"lizard", {"paper", "spock"}},
  {"spock", {"scissors", "rock"}}
};

int main() {
  std::cout << "Welcome to Rock 🪨, Paper 📄, Scissors ✂️, Lizard 🦎, Spock 🖖 !\n"; 

  bool roundWon = false;
  bool tieFlag = false;
  int userPoints = 0;
  int computerPoints = 0;

  // Play round
  while(!roundWon) {
    std::string userChoice = getUserChoice();
    std::string computerChoice = getComputerChoice();
    std::cout << '\n';

    roundWon = compareChoices(userChoice, computerChoice, tieFlag);

    if(roundWon) {
      userPoints++;
      if(userPoints == 5) {
        std::cout << "Congratulations! You won!\n";
        break;
      }
      roundWon = false; // Reset to continue game
    } else if(!roundWon && tieFlag) {
      tieFlag = false;
      continue;
    } else {
      computerPoints++;
        if(computerPoints == 5) {
          std::cout << "The computer won...\n(╯°□ °)╯︵ ┻━┻ \n";
          break;
        }
    }
    std::cout << "Points -\nUser points: "
                  << userPoints << "\nComputer points: " << computerPoints << "\n";
  }
  
  return 0;
}

// Function definitions 

// Convert User choice to lowercase then check for valid input in checkUserChoice
std::string getUserChoice() {
  std::string userChoice;
  
  while(true) {
    std::cout << "Please enter a choice: ";
    std:: cin >> userChoice;

    makeLower(userChoice);

    if(checkUserChoice(userChoice)) {
      return userChoice;
    }
  }  
}

// Generate a random number between 1 & 5 representing the 5 different moves and return a corresponding string 
std::string getComputerChoice() {
  std::string computerChoice;
  
  const int min = 1;
  const int max = 5;

  int randomValue;
  
  // Random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(min, max);
  randomValue = distrib(gen);

  switch(randomValue) {
    case 1:
      return "rock";
      break;
    case 2: 
      return "paper";
      break;
    case 3:
      return "scissors";
      break;
    case 4:
      return "lizard";
      break;
    case 5:
      return "spock";
      break;
    default:
      std::cout << "Something went wrong." << std::endl;
      exit(1);
  }
}

// Validate if the User input 
bool checkUserChoice(std::string choice) {
  if(std::cin.fail() || defeats.find(choice) == defeats.end()) {
    std::cerr << "Invalid input. Please try again." << std::endl;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    
    return false;
  } 

  return true;
}

// Convert string to all lower case
void makeLower(std::string& word) {
  for(char &c : word) {
      c = tolower(c);
    }
}

// Output results and then compare userChoice and computerChoice. Return true if the user wins but false in any other case
bool compareChoices(const std::string& uChoice, const std::string& compChoice, bool& tieFlag) {
  auto it = defeats.find(uChoice);

  std::cout << "User chose: " << uChoice << "\n";
  std::cout << "Computer chose: " << compChoice << "\n";

  if(it != defeats.end()) {
    for(std::string i : it->second) {
      if(uChoice == compChoice) { // Tie
        std::cout << "You tied! 🫠\n";
        tieFlag = true;
        return false;
      } 
      if(i == compChoice) { // Win
        std::cout << "You won! 🙌\n";
        return true;
      }
    }
    std::cout << "You lost...😔\n";
    return false;
   }
}
