#include <cctype>
#include <iostream>
#include "token.h"
using namespace std;

enum State {
	st_begin,
	st_number,
	st_float,
	st_save_number,
	st_save_float,
	st_id,
	st_save_id,
	st_save_sum,
	st_save_sub,
	st_asterisk,
	st_save_multi,
	st_save_power,
	st_save_div,
	st_save_semicolon,
	st_save_file_end
};

class Scanner {
	string _src_text;
	int _start = 0;
	int _current = 0;
	int _src_size = 0;
	int state = st_begin;

public:

	Scanner() = default;
	Scanner(string _src_text) : _src_text(_src_text), _src_size(_src_text.size()) { }

	char next_char() {
		int c = _src_text[_current];
		if (c != '\0') { ++_current; }
		return c;
	}

	void roll_back() {
		if (_src_text[_current] != '\0') { --_current; }
	}

	bool is_whitespace(char c) {
		return (c == ' ' || c == '\n' || c == '\n');
	}

	Token* next_token() {
		_start = _current;
		state = st_begin;
		while (true) {
			switch (state) {
				case st_begin:
				{
					char c = next_char();
					if (is_whitespace(c)) { _start = _current; state = st_begin; }
					else if (isdigit(c)) { state = st_number; }
					else if (isalpha(c)) { state = st_id; }
					else if (c == '+') { state = st_save_sum; }
					else if (c == '-') { state = st_save_sub; }
					else if (c == '*') { state = st_asterisk; }
					else if (c == '/') { state = st_save_div; }
					else if (c == ';') { state = st_save_semicolon; }
					else if (c == '\0') { state = st_save_file_end; }
					break;
				}

				case st_number:
				{
					char c = next_char();
					if (isdigit(c)) { state = st_number; }
					else if (c == '.') { state = st_float; }
					else { state = st_save_number; }
					break;
				}
				
				case st_float:
				{
					char c = next_char();
					if (isdigit(c)) { state = st_float; }
					else { state = st_save_float; }
					break;
				}

				case st_save_number:
				{
					roll_back();
					return new Token(NUMBER, _src_text.substr(_start, _current - _start));
				}

				case st_save_float:
				{
					roll_back();
					return new Token(FLOATING, _src_text.substr(_start, _current - _start));
				}

				case st_id:
				{
					char c = next_char();
					if (isalnum(c)) { state = st_id; }
					else { state = st_save_id; }
					break;
				}

				case st_save_id:
				{
					roll_back();
					return new Token(IDENTIFIER, _src_text.substr(_start, _current - _start));
				}

				case st_asterisk:
				{
					char c = next_char();
					if (c == '*') { state = st_save_power; }
					else { state = st_save_multi; }
					break;
				}

				case st_save_sum:
				{
					return new Token(SUM, "+");
				}

				case st_save_sub:
				{
					return new Token(SUB, "-");
				}

				case st_save_multi:
				{
					roll_back();
					return new Token(MULTI, "*");
				}

				case st_save_div:
				{
					return new Token(DIV, "/");
				}

				case st_save_power:
				{
					return new Token(POWER, "**");
				}

				case st_save_semicolon:
				{
					return new Token(SEMICOLON, ";");
				}

				case st_save_file_end:
				{
					return new Token(FILE_END, "");
				}
			}
		}
	}


};
