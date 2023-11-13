#pragma once
#include "string"
using namespace std;

class SymNode {
public:
    string key;
    int height;
    unsigned long long count = 0;
    double score = 0;
    
    SymNode* par = NULL;
    SymNode* left = NULL;
    SymNode* right = NULL;

    SymNode();
    // SymNode(SymNode&& source);
    // SymNode(SymNode& source);
    
    SymNode(const SymNode& other);
    SymNode(string k);

    SymNode* LeftLeftRotation(); // case 1
    SymNode* RightRightRotation(); // case 2
    SymNode* LeftRightRotation(); // case 3
    SymNode* RightLeftRotation(); // case 4

    ~SymNode();
    
};