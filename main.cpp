#include <iostream>
#include <string>
#include <fstream>
#include <ctime>   // Header for timestamp logic

int main() {
    std::string studentName;
    double score1, score2, average;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {

        std::cout << "\nEnter student name: ";
        // We removed cin.ignore from here because it's now handled at the bottom
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

        // --- LOGGING TO FILE WITH TIMESTAMP ---
        std::ofstream logFile;
        logFile.open("access_log.txt", std::ios_base::app);

        if (logFile.is_open()) {
            // Logic to get the current date and time
            time_t now = time(0);
            char dt[26];
            ctime_s(dt, sizeof(dt), &now);

            // Removing the hidden newline character ctime adds to the end of dt
            std::string timeStr(dt);
            if (!timeStr.empty() && timeStr.back() == '\n') timeStr.pop_back();

            logFile << "[" << timeStr << "] Name: " << studentName << " | Grade: " << average << "%" << std::endl;
            logFile.close();
            std::cout << "(Result logged to access_log.txt)" << std::endl;
        }

        std::cout << "\nWould you like to enter another student? (y/n): ";
        std::cin >> choice;

        // --- THE BUFFER FIX ---
        // This clears the 'Enter' key from the choice input 
        // so it doesn't break the name input on the next loop.
        std::cin.ignore(1000, '\n');
    }

    std::cout << "Goodbye!" << std::endl;
    return 0;
}