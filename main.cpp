#include <fstream>
#include <iterator>
#include "scanner.h"
using namespace std;

int main() {
	ifstream my_file ("./input/input.txt");
	string _src_text = { istreambuf_iterator<char>(my_file), istreambuf_iterator<char>() };
	Scanner scanner (_src_text);
	Token* next_token;
	while (true) {
		next_token = scanner.next_token();
		next_token->print();
		if (next_token->get_type() == FILE_END) { break; }
	}
}
