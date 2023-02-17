#include "slang.hpp"

#include "tree.hpp"

#include <map>

std::map<int, Node *> addresses;

int store_node(Node *node)
{
    int address = rand();
    while (addresses.count(address))
    {
        address = rand();
    }
    addresses[address] = node;
    return address;
}

Node *get_node(int address)
{
    return addresses[address];
}