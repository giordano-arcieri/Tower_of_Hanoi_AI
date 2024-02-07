#ifdef TREE_HPP
#define TREE_HPP

#include <memory>
#include <vector>

template <typename T>
struct Node
{
    T data;
    std::vector<std::shared_ptr<Node>> children;
};

template <typename T>
class Tree
{
private:
    T root;

public:
};

#endif // TREE_HPP