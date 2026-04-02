#include <fstream>
#include <iterator>
#include "scanner.h"
using namespace std;

int main() {
	ifstream my_file ("./input/input.txt");
	string _src_text = { istreambuf_iterator<char>(my_file), istreambuf_iterator<char>() };
	Scanner scanner (_src_text);
	Token* next_token;
	string _dest_text = "";
	string _route = "./input/";
	while (true) {
		next_token = scanner.next_token();
		_dest_text += next_token->get_string();
		next_token->print();
		if (next_token->get_type() == FILE_END) { break; }
	}
	delete next_token;
	ofstream("./input/output.txt") << _dest_text;
}
