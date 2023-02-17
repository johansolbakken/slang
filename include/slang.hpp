#pragma once

#include "parser.tab.hpp"
#include "tree.hpp"

extern int yylex();
extern int yyerror(const char *error);
extern int yylineno;
int yyparse();

int yylex_destroy();

int store_node(Node *node);
Node *get_node(int address);