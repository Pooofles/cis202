#include "tree.h"
#include <iostream>
using namespace std;

Tree::Tree()
{
    root = nullptr;
}

Tree::Tree(std::string root_data)
{
    root = new Node;
    root->data = root_data;
}

void Tree::add_subtree(const Tree& subtree)
{
    root->children.push_back(subtree.root);
}

int Tree::size() const
{
    if (root == nullptr) { return 0; }
    else { return root->size(); }
}

void Tree::print() const
{
    if (root != nullptr)
    {
        root->print();
    }
}

void Node::print() const
{
    cout << data << endl;
    
    for (Node* np : children) 
    {
        np->print();
    }
}

int Node::size() const
{
    int sum = 0;
    for (Node* child : children)
    {
        sum = sum + child->size();
    }
    return 1 + sum;
}
