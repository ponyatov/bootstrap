#include "hpp.hpp"
#define YYERR "\n\n"<<yylineno<<":"<<msg<<"["<<yytext<< "]\n\n"
void yyerror(string msg) { cout << YYERR; cerr << YYERR; exit(-1); }
int main() { return yyparse(); }

Sym::Sym(string T, string V) { tag=T; val=V; }		// main constructor
Sym::Sym(string V): Sym("sym",V) {}					// token constructor

string Sym::dump() { return "<"+tag+":"+val+">"; }	// dump symbol

Num::Num(string V): Sym("num",V) {}					// floating point

Int::Int(string V): Sym("int",V) {}					// integer number

