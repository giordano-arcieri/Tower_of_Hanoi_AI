#ifndef NODE_HPP
#define NODE_HPP

// I am using standerd shared pointers instead of raw ones. This means I dont need a destructor and it makes things a lot simpler/safer. There are some benifits to raw pointers that might make you want to switch to them.
#include <memory>

// This is a simple struct. Maybe it would be better to use get and set functions instead or have some added interface.
template <typename T>
struct Node
{
    T value;
    std::shared_ptr<Node<T>> next;

    Node(const T &value, Node<T> *next = nullptr)
        : value(value), next(next) {}
};

#endif