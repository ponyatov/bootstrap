#include "hpp.hpp"
#define YYERR "\n\n"<<yylineno<<":"<<msg<<"["<<yytext<< "]\n\n"
void yyerror(string msg) { cout << YYERR; cerr << YYERR; exit(-1); }
int main() { return yyparse(); }

Sym::Sym(string T, string V) { tag=T; val=V; }		// main constructor
Sym::Sym(string V): Sym("sym",V) {}					// token constructor
void Sym::push(Sym*o) { nest.push_back(o); }		// push nested element

string Sym::dump(int depth) {						// dump symbol
	string S = "\n"+pad(depth)+tagval();
	for (auto it=nest.begin(),e=nest.end();it!=e;it++)	// recursion
		S += (*it)->dump(depth+1);
	return S; }
string Sym::tagval() {								// return <tag:val> header
	return "<"+tag+":"+val+">"; }
string Sym::pad(int n) {							// left pad with n tabs
	string S;
	for (int i=0;i<n;i++) S+='\t';
	return S; }

Num::Num(string V): Sym("num",V) {}					// floating point

Int::Int(string V): Sym("int",V) {}					// integer number

Op::Op(string V): Sym("op",V) {}					// operator
