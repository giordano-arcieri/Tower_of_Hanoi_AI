#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include <vector>
#include <iostream>

template <typename T>
struct Node
{
    T value;
    std::shared_ptr<Node<T>> parent;
    std::vector<std::shared_ptr<Node<T>>> children;

    Node(T val)
    {
        value = val;
        // parent and children are initialized by default constructors
    }
};

template <typename T>
class Tree
{
private:
    // The object will simpy just keep a pointer to the root node. The tree is then travarsable as each node has a pointer to its parent and all its children.
    std::shared_ptr<Node<T>> root;

public:
    Tree();        // Initializes the root to nullptr
    Tree(T value); // Initializes the root to a node with the given value
    std::shared_ptr<Node<T>> getRoot() const;
    std::shared_ptr<Node<T>> createRoot(T value); // If the root is not null, it will not be changed
    std::shared_ptr<Node<T>> addChild(std::shared_ptr<Node<T>> parent, T value);
    void printTree() const;

private:
    void printTreeHelper(std::shared_ptr<Node<T>> node, std::string indent) const;

};


template <typename T>
Tree<T>::Tree()
{
    this->root = nullptr;
}

template <typename T>
Tree<T>::Tree(T value)
{
    this->root = std::make_shared<Node<T>>(value);
    this->root.get()->parent = nullptr;
}

template <typename T>
std::shared_ptr<Node<T>> Tree<T>::getRoot() const
{
    return this->root;
}

template <typename T>
std::shared_ptr<Node<T>> Tree<T>::createRoot(T value)
{
    if (!this->root)
    {
        this->root = std::make_shared<Node<T>>(value);
        this->root.get()->parent = nullptr;
        // parent = nullptr;
    }
    return this->root;
}

template <typename T>
std::shared_ptr<Node<T>> Tree<T>::addChild(std::shared_ptr<Node<T>> parent, T value)
{
    if (!parent)
    {
        return nullptr; // This can also be changed to throw an exception
    }
    std::shared_ptr<Node<T>> child = std::make_shared<Node<T>>(value);
    child->parent = parent;
    parent->children.push_back(child);
    return child;
}

template <typename T>
void Tree<T>::printTree() const
{
    if (!this->root)
    {
        std::cout << "Tree is empty\n";
        return;
    }
    printTreeHelper(this->root, "");
}

template <typename T>
void Tree<T>::printTreeHelper(std::shared_ptr<Node<T>> node, std::string indent) const
{
    std::cout << indent << node->value << "\n";
    for (auto child : node->children)
    {
        printTreeHelper(child, indent + "  ");
    }
}

#endif // TREE_HPP