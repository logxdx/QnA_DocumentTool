/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include <iostream>
#include "symnode.h"

//Write your code below this line

int maintainheight(SymNode* root)
{
    if (root == NULL)
    {
        return -1;
    }

    else
    {
        int h = 1 + max(maintainheight(root->left),maintainheight(root->right));
        root->height = h;
        return h;
    }
    
}

SymNode::SymNode()
{
    key = "";
    height = -1;
    count = 0;

    par = NULL;
    left = NULL;
    right = NULL;

}

// SymNode::SymNode(SymNode &&source)
// {
//     cout << "moving node" << endl;
//     key = source.key;
//     height = source.height;
//     count = source.count;
//     par = source.par;
//     left = source.left;
//     right = source.right;
// }

// SymNode::SymNode(SymNode &source)
// {
//     cout << "copying";
//     key = source.key;
//     height = source.height;
//     count = source.count;
//     par = source.par;
//     left = source.left;
//     right = source.right;

// }

SymNode::SymNode(const SymNode& other)
    : key(other.key), height(other.height), count(other.count),
      score(other.score), par(other.par), left(nullptr), right(nullptr)
{
    // Additional code if needed
    //cout << "copy node" << key;
}

SymNode::SymNode(string k)
{
    key = k;
    height = 0;
    count = 1;

    par = NULL;
    left = NULL;
    right = NULL;

}

SymNode* SymNode::LeftLeftRotation()
{
    SymNode* y = right;
    
    if (y->left != NULL)
    {
        right = y->left;
        y->left->par = this;
        y->left = NULL;
        y->par = NULL;
    }
    else
    {
        right = NULL;
        y->par = NULL;
    }
    
    
    if (par == NULL)
    {
        par = y;
        y->left = this;
        
    }

    else if (par->left == this)
    {
        par->left = y;
        y->par = par;
        par = NULL;
    }

    else
    {
        par->right = y;
        y->par = par;
        par = NULL;
    }

    par = y;
    y->left = this;

    SymNode* r = par;
    while (r->par != NULL)
    {
        r = r->par;
    }

    maintainheight(r);
    return r;

}

SymNode* SymNode::RightRightRotation()
{
    SymNode* x = left;

   if (x->right != NULL)
   {
        left = x->right;
        x->right->par = this;
        x->right = NULL;
        x->par = NULL;
   }
   else
    {
        left = NULL;
        x->par = NULL;
    }

   if (par == NULL)
   {
        par = x;
        x->right = this;
   }

   else if (par->right == this)
   {
        par->right = x;
        x->par = par;
        par = NULL;

   }

   else
   {
        par->left = x;
        x->par = par;
        par = NULL;
   }

   par = x;
   x->right = this;

    SymNode* r = par;
    while (r->par != NULL)
    {
        r = r->par;
    }

    maintainheight(r);
    return r;
   
}

SymNode* SymNode::LeftRightRotation()
{
    left->LeftLeftRotation();
    RightRightRotation();
    SymNode* r = par;
    while (r->par != NULL)
    {
        r = r->par;
    }

    return r;

}

SymNode* SymNode::RightLeftRotation()
{
    right->RightRightRotation();
    LeftLeftRotation();
    SymNode* r = par;
    while (r->par != NULL)
    {
        r = r->par;
    }

    return r;
}

// void delsubtree(SymNode* root)
// {
//     if (root != nullptr)
//     {
//         delsubtree(root->left);
//         delsubtree(root->right);
//         delete root;
//     }
    
// }

SymNode::~SymNode()
{
   // cout << "mem free at " << key << endl;
}

/*
int main()
{
    SymNode a("z");
    SymNode b("x");
    SymNode c("y");
    a.left = &b;
    b.par = &a;
    c.par = &b;
    b.right = &c;
    //a.LeftRightRotation();
    //cout << c.left->height;

    //std::cout << "dnoe";


}*/