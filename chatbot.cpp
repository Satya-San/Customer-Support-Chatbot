#include "chatbot.h"

Chatbot::Chatbot() {
    root = getNode();
}

Chatbot::TrieNode* Chatbot::getNode() {
    return new TrieNode();
}

void Chatbot::addResponse(const std::string& keyword, const std::string& response) {
    insert(keyword, response);
}

void Chatbot::insert(const std::string& keyword, const std::string& response) {
    TrieNode* node = root;
    for (char ch : keyword) {
        if (!node->children[ch]) {
            node->children[ch] = getNode();
        }
        node = node->children[ch];
    }
    node->isEndOfWord = true;
    node->response = response;
}

std::string Chatbot::search(const std::string& keyword) {
    TrieNode* node = root;
    for (char ch : keyword) {
        if (!node->children[ch]) {
            return "I'm sorry, I don't understand that query.";
        }
        node = node->children[ch];
    }
    return node->isEndOfWord ? node->response : "I'm sorry, I don't understand that query.";
}

std::string Chatbot::getResponse(const std::string& query) {
    return search(query);
}

int main() {
    Chatbot bot;

    // Adding some common responses
    bot.addResponse("hello", "Hello! How can I help you today?");
    bot.addResponse("hours", "Our hours of operation are 9 AM to 5 PM, Monday to Friday.");
    bot.addResponse("price", "Please visit our website for pricing information.");
    bot.addResponse("support", "You can reach our support team at support@example.com.");

    std::string query;
    std::cout << "Welcome to the Customer Support Chatbot! Type 'exit' to end the chat." << std::endl;

    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, query);
        if (query == "exit") break;
        std::string response = bot.getResponse(query);
        std::cout << "Bot: " << response << std::endl;
    }

    return 0;
}
