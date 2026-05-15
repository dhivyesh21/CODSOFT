#include <iostream>
#include <string>
#include <algorithm>
void printLine() {
    std::cout << "------------------------------------------" << std::endl;
}
int main() {
    std::string input;
    printLine();
    std::cout << "   CODSOFT AI ASSISTANT: ONLINE" << std::endl;
    printLine();
    std::cout << "Bot: Hello! I'm your assistant. How can I help you today?" << std::endl;
    std::cout << "(Type 'exit' or 'bye' to end the chat)" << std::endl;

    while (true) {
        std::cout << "\nYou: ";
        std::getline(std::cin, input);
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);

        if (input == "exit" || input == "bye") {
            std::cout << "Bot: Goodbye! Have a great day!" << std::endl;
            break;
        } 
        else if (input.find("hello") != std::string::npos || input.find("hi") != std::string::npos) {
            std::cout << "Bot: Hi there! Hope you are having a productive day." << std::endl;
        } 
        else if (input.find("name") != std::string::npos || input.find("who are you") != std::string::npos) {
            std::cout << "Bot: I am a rule-based AI chatbot developed for my internship." << std::endl;
        } 
        else if (input.find("help") != std::string::npos) {
            std::cout << "Bot: I can answer basic questions or just have a small chat with you!" << std::endl;
        }
        else {
            std::cout << "Bot: That sounds interesting! I'm still learning, so tell me more." << std::endl;
        }
    }
    return 0;
}
