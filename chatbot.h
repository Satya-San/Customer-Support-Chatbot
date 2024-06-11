#ifndef CHATBOT_H
#define CHATBOT_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Chatbot {
public:
    Chatbot();
    void addResponse(const std::string& keyword, const std::string& response);
    std::string getResponse(const std::string& query);
    
private:
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children;
        std::string response;
        bool isEndOfWord;
        TrieNode() : isEndOfWord(false) {}
    };
    
    TrieNode* root;
    TrieNode* getNode();
    void insert(const std::string& keyword, const std::string& response);
    std::string search(const std::string& keyword);
};

#endif
