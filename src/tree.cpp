#include "tree.hpp"

const char *node_type_string[] = {
    "PROGRAM",
    "GLOBAL_LIST",
    "GLOBAL",
    "DECLARATION",
    "VARIABLE_LIST",
    "VARIABLE",
    "ARRAY_DECLARATION",
    "ARRAY_INDEXING",
    "FUNCTION",
    "PARAMETER_LIST",
    "STATEMENT",
    "BLOCK",
    "DECLARATION_LIST",
    "STATEMENT_LIST",
    "ASSIGNMENT_STATEMENT",
    "RETURN_STATEMENT",
    "PRINT_STATEMENT",
    "PRINT_LIST",
    "PRINT_ITEM",
    "BREAK_STATEMENT",
    "RELATION",
    "ARGUMENT_LIST",
    "EXPRESSION_LIST",
    "EXPRESSION",
    "IDENTIFIER_DATA",
    "INT_DATA",
    "FLOAT_DATA",
    "STRING_DATA"};

const char *nodeTypeToString(NodeType type)
{
    return node_type_string[(int)type];
}

void finalize_subtree(Node *node)
{
    for (auto child : node->children)
    {
        finalize_subtree(child);
        delete child;
    }
}

Node::Node(NodeType type, const std::vector<Node *> &children)
    : type(type), children(children)
{
}

Node::~Node()
{
    delete data;
}

void Node::print(int indent)
{
    for (int i = 0; i < indent; i++)
        std::cout << " ";
    std::cout << nodeTypeToString(type) << std::endl;
    for (const auto &child : children)
        child->print(indent + 2);
}

StringNode::StringNode(const std::string &text)
    : Node(NodeType::STRING_DATA, {}), text(text)
{
}

void StringNode::print(int indent)
{
    for (int i = 0; i < indent; i++)
        std::cout << " ";
    std::cout << nodeTypeToString(type) << " " << text << std::endl;
}

IdentifierNode::IdentifierNode(const std::string& name)
    : Node(NodeType::IDENTIFIER_DATA, {}), name(name)
{
}

void IdentifierNode::print(int indent) {
for (int i = 0; i < indent; i++)
        std::cout << " ";
    std::cout << nodeTypeToString(type) << " " << name << std::endl;
} 