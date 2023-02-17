#include "slang.hpp"

#include "tree.hpp"

#include <map>

std::map<int, Node *> addresses;
int address_insert = 0;

int store_node(Node *node)
{
    address_insert++;
    addresses[address_insert] = node;
    return address_insert;
}

Node *get_node(int address)
{
    return addresses[address];
}