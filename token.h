#include <iostream>
#include <string_view>
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
	LEFT_PTHS,
	RIGHT_PTHS,
	CONSTANT,
	FUNCTION,
	SEMICOLON,
	FILE_END
};

class Token {
	Type _type = Type::DEFAULT;
	string _lex;
	string _res = "";

public:
	
	Token() = default;
	Token(Type _type, string _lex) : _type(_type), _lex(_lex) { }

	Type get_type() { return _type; }

	void set_print_type() {
		_res = "TOKEN(";
		switch (_type) {
			case DEFAULT:
				_res += "DEFAULT"; break;
			case NUMBER:
				_res += "NUMBER"; break;
			case FLOATING:
				_res += "FLOAT"; break;
			case IDENTIFIER:
				_res += "IDENTIFIER"; break;
			case SUM:
				_res += "SUM"; break;
			case SUB:
				_res += "SUB"; break;
			case MULTI:
				_res += "MULTI"; break;
			case DIV:
				_res += "DIV"; break;
			case POWER:
				_res += "POWER"; break;
			case SEMICOLON:
				_res += "SEMICOLON"; break;
			case LEFT_PTHS:
				_res += "LEFT_PTHS"; break;
			case RIGHT_PTHS:
				_res += "RIGHT_PTHS"; break;
			case CONSTANT:
				_res += "CONSTANT"; break;
			case FUNCTION:
				_res += "FUNCTION"; break;
			case FILE_END:
				_res += "FILE_END"; break;
		}
		_res += ", \"" + _lex + "\")\n";
	}

	void print() {
		if (_res == "") { set_print_type(); }
		cout << _res;
	}

	string_view get_string() {
		if (_res == "") { set_print_type(); }
		return _res;
	}
};
