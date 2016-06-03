#ifndef _H_BOOTSTRAP
#define _H_BOOTSTRAP

#include <iostream>		// C++ streamed I/O library
#include <cstdlib>		// required for exit(error)
#include <vector>		// STL container used for nested SYMbols
#include <map>			// STL container for lookup table
using namespace std;

struct Sym {
	string tag;					// data type/class
	string val;					// data element value
	// --------------------------- constructors
	Sym(string T,string V);		// <tag:value> constructor
	Sym(string V);				// token constructor
	// --------------------------- nested elements
	vector<Sym*> nest;			// container
	void push(Sym*);			// add element
	// --------------------------- dumping in string form
	virtual string dump();		// full dump
};

struct Num: Sym { Num(string); float val; };	// floating point
struct Int: Sym { Int(string); int val; };		// integer number

extern int yylex();				// lexer interface
extern int yylineno;			// current lexer line number
extern char* yytext;			// text matched by lexer
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();			// parser interface
extern void yyerror(string);	// error callback
#include "ypp.tab.hpp"

#endif // _H_BOOTSTRAP
