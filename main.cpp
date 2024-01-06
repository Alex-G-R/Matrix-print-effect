#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

const int WIDTH = 80; // of the console
const int HEIGHT = 25; // of the console

void printMatrixEffect(const std::string& targetText) {
    // set-up random seed
    std::srand(static_cast<unsigned>(std::time(0)));

    // matrix effect loop
    std::string currentDisplay(targetText.size(), ' ');  // init with spaces

    for (size_t i = 0; i < targetText.size(); ++i) {
        if (targetText[i] != ' ') {
            currentDisplay[i] = targetText[i];
        }

        for (size_t j = 0; j < targetText.size(); ++j) {
            if (targetText[j] == ' ') {
                std::cout << ' ';  // reveal spaces
            } else {
                std::cout << (currentDisplay[j] != ' ' ? currentDisplay[j] : static_cast<char>('A' + std::rand() % 26));
            }
        }

        std::cout << std::endl;

        // sleep to control the speed of the matrix effect
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // wipe the console screen
        system("cls");  // For Windows
        // system("clear");  // For Linux/Mac
    }

    // print the fully revealed text at the end
    std::cout << targetText << std::endl;
}

int main() {
    std::string targetText = "I will be back ~ Terminator (i guess) -> that's what joe mama said";
    printMatrixEffect(targetText);
    std::cin.get();
    return 0;
}
