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
    Node(NodeType type, int nChildren)
        : type(type), nChildren(nChildren)
    {
        if (nChildren > 0)
        {
            ppChildren = new NodeRef[nChildren];
        }
    }

    virtual ~Node()
    {
    }

    virtual void print(int indent = 0)
    {
        for (int i = 0; i < indent; i++)
            std::cout << " ";
        std::cout << nodeTypeToString(type) << std::endl;
        std::cout << ppChildren[0] << std::endl;
        for (int i = 0; i < nChildren; i++)
            ppChildren[i]->print(indent + 2);
    }

    NodeType type;
    void *data = nullptr;
    int nChildren = 0;
    Node **ppChildren = nullptr;
};

class StringNode : public Node
{
public:
    StringNode(const std::string &text)
        : Node(NodeType::STRING_DATA, 0), text(text)
    {
    }
    ~StringNode() override = default;

    std::string text;
};

class IntNode : public Node
{
public:
    IntNode();
    ~IntNode() override;

    int number;
};
