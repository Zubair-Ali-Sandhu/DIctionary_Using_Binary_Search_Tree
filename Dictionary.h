#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>

class Node {
public:
    std::string word;
    std::string meaning;
    Node *left;
    Node *right;

    Node(std::string word, std::string meaning);
};

class Dictionary {
public:
    Node *root;

    Node *insert(Node *root, std::string word, std::string meaning);
    Node *minValueNode(Node *node);
    Node *deleteNode(Node *root, std::string word);
    Node *search(Node *root, std::string word);
    void inorder(Node *root, std::string word, std::vector<std::string> &suggestions);
    void LoadDictionary(Node *&root);
    void AddWord(Node *&root, std::string word, std::string meaning);
    void SearchWord(Node *&root, std::string word);
    void DeleteWord(Node *&root, std::string word);
    void UpdateWord(Node *&root, std::string word, std::string newMeaning);
    void WordSuggestion(Node *root, std::string word);
    void writeInorder(Node *root, std::ofstream &file);
    void writeDictionary(Node *root);
};

#endif // DICTIONARY_H