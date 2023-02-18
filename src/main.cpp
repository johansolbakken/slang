#include <iostream>

#include "slang.hpp"

Node *root;
int main(int argc, const char **argv)
{
    yyparse();
    yylex_destroy();

    root->print();

    finalize_subtree(root);
    delete root;
}