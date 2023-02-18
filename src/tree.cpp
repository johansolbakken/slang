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

void finalize_subtree(Node* node)
{
    for (auto child : node->children)
    {
        finalize_subtree(child);
        delete child;
    }
}