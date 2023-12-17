#include <fstream>
#include "iostream"
#include "Dictionary.h"

using namespace std;


// Constructor returning new node with given word and meaning
Node::Node(string word, string meaning) {
    this->word = word;
    this->meaning = meaning;
    this->left = this->right = NULL;
}


Node *Dictionary::insert(Node *root, std::string word, std::string meaning) {
    if (root == NULL) {
        return new Node(word, meaning);
    }
    if (word < root->word) root->left = insert(root->left, word, meaning);
    else if (word > root->word) root->right = insert(root->right, word, meaning);
    return root;
}

// find minValueNode towards left Side
Node *Dictionary::minValueNode(Node *node) {
    Node *current = node;
    // keep traversing until leaf node came
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node *Dictionary::deleteNode(Node *root, string word) {
    if (root == NULL)
        return root;
    // go left side
    if (word < root->word)
        root->left = deleteNode(root->left, word);
        // go right side
    else if (word > root->word)
        root->right = deleteNode(root->right, word);
        // if word matches
    else {
        // * Case 1: one child case or no child case

        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // * Case 2: Two Child
        Node *temp = minValueNode(root->right);
        root->word = temp->word;
        root->right = deleteNode(root->right, temp->word);
    }
    return root;
}

Node *Dictionary::search(Node *root, string word) {
    if (root == NULL || root->word == word) {
        return root;
    }
    // go right
    if (root->word < word) {
        return search(root->right, word);
    }
    // else go left
    return search(root->left, word);
}

// [ Left, Root, Right]
void Dictionary::inorder(Node *root, string word, vector<string> &suggestions) {
    // * Base Case
    // if Suggestion Size >= 10, don't call anything, just leave stack
    if (root != NULL && suggestions.size() < 10) {
        inorder(root->left, word, suggestions);
        // if SubString not found, it return string::npos, otherwise 0
        if (root->word.find(word) == 0) {
            suggestions.push_back(root->word);
        }
        inorder(root->right, word, suggestions);
    }
}

void Dictionary::LoadDictionary(Node *&root) {
    ifstream file("Dictionary.txt");
    string word, meaning;
    while (file >> word >> meaning) {
        // Insert the content of dictionary into custom data structure
        root = insert(root, word, meaning);
    }
    cout << "Dictionary is loaded" << endl;
}

void Dictionary::AddWord(Node *&root, string word, string meaning) {
    if (search(root, word) == NULL) {
        root = insert(root, word, meaning);
        cout << "Word added" << endl;
    } else {
        cout << "Word already exists" << endl;
    }
}

void Dictionary::SearchWord(Node *&root, string word) {
    Node *res = search(root, word);
    if (res != NULL) {
        cout << "Meaning: " << res->meaning << endl;
    } else {
        cout << "Word not found" << endl;
    }
}

void Dictionary::DeleteWord(Node *&root, string word) {
    // if word found, delte it
    if (search(root, word) != NULL) {
        root = deleteNode(root, word);
        cout << "Word deleted" << endl;
    } else {
        cout << "Word not found" << endl;
    }
}

void Dictionary::UpdateWord(Node *&root, string word, string newMeaning) {
    Node *res = search(root, word);
    if (res != NULL) {
        res->meaning = newMeaning;
        cout << "Word updated" << endl;
    } else {
        cout << "Word not found" << endl;
    }
}

void Dictionary::WordSuggestion(Node *root, string word) {
    vector<string> suggestions;
    inorder(root, word, suggestions);
    for (string s: suggestions) {
        cout << s << endl;
    }
}

// traverse inOrder and write in the dictionary file
void Dictionary::writeInorder(Node *root, ofstream &file) {
    if (root != NULL) {
        writeInorder(root->left, file);
        file << root->word << "\t" << root->meaning << "\n";
        writeInorder(root->right, file);
    }
}

void Dictionary::writeDictionary(Node *root) {
    ofstream file("temp.txt");
    if (!file) {
        cout << "Unable to open file for writing." << endl;
        return;
    }
    writeInorder(root, file);
    file.close();
    if (rename("temp.txt", "Dictionary.txt") != 0) {
        cout << "Error updating dictionary file." << endl;
    }
}
// void writeDictionary(Node* root) {
//     ofstream file("dict.txt");
//     if (!file) {
//         cout << "Unable to open file for writing." << endl;
//         return;
//     }
//     writeInorder(root, file);
//     file.close();
// }
