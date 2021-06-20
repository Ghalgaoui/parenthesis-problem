//============================================================================
// Name        : Sequence_paretheses.cpp
// Author      : kamel
// Version     :
// Copyright   : Your copyright notice
// Description : Sequence paretheses in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;


class Answer {
public:
	static bool check(string seq){
		string parentheses = "()";
		string accolades = "[]";

		if(seq.empty())
			return true;
		if(seq == parentheses || seq == accolades ||
		   seq == parentheses + accolades || seq == accolades + parentheses
		   || seq == parentheses + parentheses || seq == accolades + accolades){
			return true;
		} else {
			if((seq[0] == '(' && seq[seq.size() - 1] == ')')
					|| (seq[0] == '[' && seq[seq.size() - 1] == ']')){
				seq.erase(seq.begin());
				seq.pop_back();
				check(seq);
			} else {
				return false;
			}
		}
	}
};

int main() {

	cout << Answer::check("([()])") << endl;
	cout << Answer::check("(()[])") << endl;
	cout << Answer::check("[][]") << endl;
	cout << Answer::check("([)]") << endl;
	cout << Answer::check("((") << endl;
	cout << Answer::check("[(())][[[[]]]]") << endl;
	return 0;
}

