#include <iostream>
using namespace std;

enum Type {
	DEFAULT,
	NUMBER,
	IDENTIFIER,
	FLOATING,
	SUM,
	SUB,
	MULTI,
	DIV,
	POWER,
	SEMICOLON,
	FILE_END
};

class Token {
	Type _type = Type::DEFAULT;
	string _lex;

public:
	
	Token() = default;
	Token(Type _type, string _lex) : _type(_type), _lex(_lex) { }

	Type get_type() { return _type; }

	void print() {
		switch (_type) {
			case DEFAULT:
				cout << "unknown: "; break;
			case NUMBER:
				cout << "number: "; break;
			case FLOATING:
				cout << "float: "; break;
			case IDENTIFIER:
				cout << "identifier: "; break;
			case SUM:
				cout << "sum operator: "; break;
			case SUB:
				cout << "sub operator: "; break;
			case MULTI:
				cout << "multi operator: "; break;
			case DIV:
				cout << "div operator: "; break;
			case POWER:
				cout << "power operator: "; break;
			case SEMICOLON:
				cout << "semicolon: "; break;
			case FILE_END:
				cout << "eof\n"; return;
		}
		cout << _lex << '\n';
	}
};
