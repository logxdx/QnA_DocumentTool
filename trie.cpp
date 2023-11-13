#include <iostream>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

// TrieNode represents a node in the trie
class TrieNode {
public:
    vector<TrieNode*> children; // Links to child nodes
    bool isEndOfWord; // Flag indicating the end of a word
    int count; // Attribute to store the count of the word

    TrieNode() : isEndOfWord(false), count(0) {
        // Initialize the children vector with null pointers for each alphabet letter
        children.resize(ALPHABET_SIZE, nullptr);
    }

    // Destructor to recursively delete child nodes
    ~TrieNode() {
        for (TrieNode* child : children) {
            if (child != nullptr) {
                delete child;
            }
        }
    }
};

// Trie class provides methods for trie operations
class Trie {

public:
    TrieNode* root;
    Trie() {
        root = new TrieNode(); // Create the root node
    }

    // Destructor to delete the entire trie
    ~Trie() {
        delete root;
    }

    // Insert a word into the trie
    void insert(const string& word) {
        TrieNode* current = root;

        // Traverse the trie, creating new nodes as needed
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }

        current->isEndOfWord = true; // Mark the end of the word
        current->count++; // Increment the count attribute
    }

    // Search for a word in the trie
    bool search(const string& word) {
        TrieNode* node = searchNode(word);
        return (node != nullptr && node->isEndOfWord);
    }

    // Get the count of a word in the trie
    int getCount(const string& word) {
        TrieNode* node = searchNode(word);
        return (node != nullptr) ? node->count : 0;
    }

private:
    // Helper function to search for a word and return the last node in the path
    TrieNode* searchNode(const string& word) {
        TrieNode* current = root;

        // Traverse the trie to find the last node in the path
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return nullptr; // Node not found
            }
            current = current->children[index];
        }

        return current;
    }
};

// Main function for testing the trie
/*
int main() {
    Trie trie;

    // Insert words into the trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("banana");

    // Search for words and print their counts
    cout << "Count of 'apple': " << trie.getCount("apple") << endl;     // Output: 1
    cout << "Count of 'app': " << trie.getCount("app") << endl;         // Output: 1
    cout << "Count of 'apricot': " << trie.getCount("apricot") << endl; // Output: 1
    cout << "Count of 'banana': " << trie.getCount("banana") << endl;   // Output: 1
    cout << "Count of 'orange': " << trie.getCount("orange") << endl;   // Output: 0

    return 0;
}*/
