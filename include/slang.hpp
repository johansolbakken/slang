#pragma once

#include "parser.tab.hpp"

extern int yylex();
extern int yyerror(const char *error);
extern int yylineno;