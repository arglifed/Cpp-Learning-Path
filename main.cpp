#include <iostream>
#include <string>

int main() {
    std::string studentName;
    double score1, score2, average;
    char choice = 'y'; // This will store if the user wants to continue

    // The 'while' loop keeps the program running as long as choice is 'y'
    while (choice == 'y' || choice == 'Y') {

        std::cout << "\nEnter student name: ";
        std::cin.ignore(); // Clears the "Enter" key from previous runs
        std::getline(std::cin, studentName);

        std::cout << "Enter first test score: ";
        std::cin >> score1;

        std::cout << "Enter second test score: ";
        std::cin >> score2;

        average = (score1 + score2) / 2;

        std::cout << "\n--- Student Report ---" << std::endl;
        std::cout << "Name: " << studentName << std::endl;
        std::cout << "Average Grade: " << average << "%" << std::endl;

        if (average >= 90) {
            std::cout << "Status: ELITE." << std::endl;
        }
        else if (average >= 60) {
            std::cout << "Status: PASSED." << std::endl;
        }
        else {
            std::cout << "Status: FAILED." << std::endl;
        }

        // Ask the user if they want to go again
        std::cout << "\nWould you like to enter another student? (y/n): ";
        std::cin >> choice;
    }

    std::cout << "Goodbye!" << std::endl;
    return 0;
}