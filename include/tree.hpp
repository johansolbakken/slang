#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "nodetypes.hpp"

const char *nodeTypeToString(NodeType type);

class Node;

using NodeRef = std::shared_ptr<Node>;
using NodeRefList = std::vector<NodeRef>;

class Node
{
public:
    Node(NodeType type, const NodeRefList &children);

    virtual ~Node();

    virtual void print(int indent = 0);

public:
    NodeType type;
    void *data = nullptr;
    void *symbol = nullptr; // unused for now
    NodeRefList children;
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
        {
            std::cout << " ";
        }

        std::cout << nodeTypeToString(type) << " \"" << text << "\"" << std::endl;
    }

    std::string text;
};

class IntNode : public Node
{
public:
    IntNode(int number)
        : Node(NodeType::INT_DATA, {}), number(number)
    {
    }
    ~IntNode() override = default;

    void print(int indent = 0) override
    {
        for (int i = 0; i < indent; i++)
        {
            std::cout << " ";
        }

        std::cout << nodeTypeToString(type) << " " << number << std::endl;
    }

    int number;
};

namespace NodeUtils
{
    inline NodeRef createNode(NodeType type, const NodeRefList &children)
    {
        auto node = std::make_shared<Node>(type, children);
        return node;
    }

    inline NodeRef createStringNode(const std::string &text)
    {
        auto node = std::make_shared<StringNode>(text);
        return node;
    }

    inline NodeRef createIntNode(int number)
    {
        auto node = std::make_shared<IntNode>(number);
        return node;
    }
}