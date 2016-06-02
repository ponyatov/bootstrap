#include "hpp.hpp"
#define YYERR "\n\n"<<yylineno<<"["<<msg<<"]\n\n"
void yyerror(string msg) { cout << YYERR; cerr << YYERR; exit(-1); }
int main() { return yyparse(); }
