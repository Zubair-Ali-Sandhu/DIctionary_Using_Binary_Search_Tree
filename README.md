# DIctionary_Using_Binary_Search_Tree
The project is a dictionary application implemented in C++ using Binary Search tree. The application allows users to add, search, delete, and update words. It also provides word suggestions based on prefixes.
Data Structures:

The primary data structure used in this project is a Binary Search Tree (BST). Each node in the BST represents a word in the dictionary and contains the word, its meaning, and pointers to the left and right child nodes.

Justification for Using BST
1.Fast Search :
 BST allows for fast search operations. The time complexity for searching a word in a BST is O(log n), where n is the number of words in the dictionary. This makes it a suitable data structure for a dictionary application where search operations are frequent.

2. Sorted Data: 
BST is sorted binary tree. The words in the dictionary are stored in a sorted manner, which is effective for providing word suggestions. When a user enters a prefix, the application can easily find all words that start with that prefix by traversing the BST.

3. Easy Operations:
 BST allows for relatively simple implementation of insert, delete, and update operations. All these operations can be performed in O(log n) time complexity.

 Code Functions:


-newNode(): Creates a new BST node.
- insert(): Inserts a new word into the BST.
- minValueNode(): Finds the node with the minimum value in the BST.
- deleteNode(): Deletes a word from the BST.
- search(): Searches for a word in the BST.
- inorder(): Performs an in-order traversal of the BST.
- LoadDictionary(): Loads the dictionary from a file into the BST.
- AddWord(), SearchWord(), DeleteWord(), UpdateWord(): Perform the operations according to their names on the dictionary.
- WordSuggestion(): Provides word suggestions based on a prefix.
- writeInorder(): Writes the BST to a file in an in-order approach in the same file.
- writeDictionary(): Writes the current changes of the dictionary to a file.

The main() function provides an interactive menu for users to perform operations on the dictionary.

Conclusion:

The dictionary application effectively utilizes the properties of a Binary Search Tree to provide efficient and user-friendly operations. The choice of BST as the main data structure enables the application to handle many words while maintaining high performance.
