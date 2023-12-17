#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Dictionary.h"

using namespace std;

// Node class having Tree Node Data members


// A Dictionary Class Implementing Binary Search Tree Operations



int main()
{
    Node::Node *root;
    root = NULL;
    Dictionary::Dictionary D1;
    D1.LoadDictionary(root);

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Add Word\n";
        cout << "2. Search Word\n";
        cout << "3. Delete Word\n";
        cout << "4. Update Word\n";
        cout << "5. Word Suggestion\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        string word, meaning;
        if (choice == 1)
        {
            cout << "Enter word > ";
            cin >> word;
            cout << "Enter meaning > ";
            cin >> meaning;
            D1.AddWord(root, word, meaning);
        }
        else if (choice == 2)
        {
            cout << "Enter word > ";
            cin >> word;
            D1.SearchWord(root, word);
        }
        else if (choice == 3)
        {
            cout << "Enter word > ";
            cin >> word;
            D1.DeleteWord(root, word);
        }
        else if (choice == 4)
        {
            cout << "Enter word: ";
            cin >> word;
            cout << "Enter new meaning > ";
            cin >> meaning;
            D1.UpdateWord(root, word, meaning);
        }
        else if (choice == 5)
        {
            cout << "Enter prefix > ";
            cin >> word;
            D1.WordSuggestion(root, word);
        }
            // Exit program on choice 6
        else if (choice == 6)
        {
            D1.writeDictionary(root);
            break;
        }
        else
        {
            cout << "!Invalid choice.\n";
        }
    }
}