/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"
#include <iostream>


//Write your code below this line
int maintainheights(SymNode* root)
{
    if (root == NULL)
    {
        return -1;
    }

    else
    {
        int h = 1 + max(maintainheights(root->left),maintainheights(root->right));
        root->height = h;
        return h;
    }
    
}

int balancefactor(SymNode* root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        return ((root->right == NULL)?0:root->right->height) - ((root->left == NULL)?0:root->left->height)  ;      
    }
    
}

SymbolTable::SymbolTable()
{
    //cout << "inta" << endl;
}
SymbolTable::SymbolTable(const SymbolTable &source)
{
   // cout << "copy " << source.root << endl;
    root = copyNodes(source.root);
    size = source.size;
}

SymNode* SymbolTable::copyNodes(SymNode* node)
{
    if (node == nullptr)
        return nullptr;

    SymNode* newNode = new SymNode(*node);
    newNode->left = copyNodes(node->left);
    newNode->right = copyNodes(node->right);

    return newNode;
}
void SymbolTable::insert(string k)
{
    SymNode* newnode = new SymNode(k);

    if (size == 0)
    {
        root = newnode;
        size++;
    }

    else
    {
        SymNode* head = root;
        while (head != NULL)
        {
            if (head->key > k)
            {
                if (head->left == NULL)
                {
                    head->left = newnode;
                    newnode->par = head;
                    size++;
                    break;
                }
                else
                {
                    head = head->left;
                }
            }

            else if(head->key < k)
            {
                if(head->right == NULL)
                {
                    head->right = newnode;
                    newnode->par = head;
                    size++;
                    break;
                }
                else
                {
                    head = head->right;
                }
                
            }

            else{head->count++; return;}
            
        }
        
        maintainheights(root);
        SymNode* traversal = newnode;
        while (true)
        {
            int e = balancefactor(traversal);
            if (e == 2 or e == -2)
            {
                break;
            }
            else
            {
                if (traversal->par != NULL)
                {
                    traversal = traversal->par;
                }

                else
                {
                    traversal = traversal->par;
                    break;
                }
            }
            
        }
        

        if (traversal == NULL)
        {
            return;
        }

        SymNode* y;
        if (traversal->key > k)
        {
            y = traversal->left;
        }
        else{y = traversal->right;}

        SymNode* x;
        if (y->key > k)
        {
            x = y->left;
        }
        else{x = y->right;}

        if (traversal->left == y and y->left == x)
        {
            root = traversal->RightRightRotation();
        }
        
        else if (traversal->left == y and y->right == x)
        {
            root = traversal->LeftRightRotation();
        }

        else if (traversal->right == y and y->right == x)
        {
            root = traversal->LeftLeftRotation();
        }

        else{root = traversal->RightLeftRotation();}

        maintainheights(root);
    }
}

unsigned long long SymbolTable::search(string k)
{
    SymNode* head = root;
    while (head != NULL)
    {
        if (head->key == k)
        {
            break;
        }
        
        else if (head->key < k)
        {
            head = head->right;
        }

        else{head = head->left;}

        if (head == NULL)
        {
            break;
        }
    }

    if (head == NULL)
    {
        return 0;
    }

    else{return head->count;}
    return 0;
    

}

int SymbolTable::get_size()
{
    return size;

}

SymNode* SymbolTable::get_root()
{
    return root;

}

void destroy(SymNode* root)
{
    if (root != NULL)
    {
        destroy(root->left);
        destroy(root->right);
        //cout << "cleared "<< root->key <<endl;
        delete(root);
        root = nullptr;
    }
    
}

SymbolTable::~SymbolTable()
{
    //cout << "into destro" << endl;
    destroy(root);
    root = nullptr;
    //free(root);
}

// void print_AVL_Tree(SymNode* root, int depth = 0) {
    
//     for (int i = 0; i < depth; ++i) {
//         std::cout << "  ";
//     }
//     cout << root->key << endl;
    
//     if (root->left != nullptr) {
//         print_AVL_Tree(root->left, depth+1);
//     }
//     if (root->right != nullptr) {
//         print_AVL_Tree(root->right, depth + 1);
//     }
// }

// int main()
// {
//     SymbolTable a;
//     a.insert("a");
//     a.insert("b");
//     a.insert("c");
//     a.insert("e");
//     a.insert("d");
//     // a.insert("6");
//     // a.insert("7");
//     // a.insert("8");

//     // a.remove("6");
//     // a.remove("5");
//     // a.remove("4");
//     // a.remove("3");
//    // print_AVL_Tree(a.get_root());
//    a.remove("a");
//    a.remove("b");
//     cout << "done";
// }
