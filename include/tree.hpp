#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include "nodetypes.hpp"

const char *nodeTypeToString(NodeType type);

class Node
{
public:
    Node(NodeType type, const std::vector<Node *> &children);
    virtual ~Node();
    virtual void print(int indent = 0);

public:
    NodeType type;
    void *data = nullptr;
    std::vector<Node *> children;
};

class StringNode : public Node
{
public:
    StringNode(const std::string &text);
    ~StringNode() override = default;
    void print(int indent = 0) override;

    std::string text;
};

class IntNode : public Node
{
public:
    IntNode();
    ~IntNode() override;

    int number;
};

class IdentifierNode : public Node
{
public:
    IdentifierNode(const std::string& name);
    ~IdentifierNode() override = default;
    void print(int indent = 0) override;

public:
    std::string name;
};

void finalize_subtree(Node *node);