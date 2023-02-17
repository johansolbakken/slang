#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "nodetypes.hpp"

const char *nodeTypeToString(NodeType type);

class Node;
using NodeRef = Node *;
class Node
{
public:
    Node(NodeType type, const std::vector<Node *> &children)
        : type(type), children(children)
    {
    }

    virtual ~Node()
    {
    }

    virtual void print(int indent = 0)
    {
        for (int i = 0; i < indent; i++)
            std::cout << " ";
        std::cout << nodeTypeToString(type) << std::endl;
        for (const auto &child : children)
            child->print(indent + 2);
    }

    NodeType type;
    void *data = nullptr;
    std::vector<Node *> children;
};

class StringNode : public Node
{
public:
    StringNode(const std::string &text)
        : Node(NodeType::STRING_DATA, {}), text(text)
    {
    }
    ~StringNode() override = default;

    void print(int indent = 0) override
    {
        for (int i = 0; i < indent; i++)
            std::cout << " ";
        std::cout << nodeTypeToString(type) << " " << text << std::endl;
    }

    std::string text;
};

class IntNode : public Node
{
public:
    IntNode();
    ~IntNode() override;

    int number;
};
