#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	int test = 1;
	bool cmp = false;
	ifstream p1("std_data.txt");
	ifstream p2("yours_data.txt");
	ofstream p3("judge.txt");
	while (!p1.eof() && !p2.eof()) {
		string number1, number2;
		string sort1, sort2;
		string result1, result2;
		getline(p1, number1);
		getline(p2, number2);
		getline(p1, sort1);
		getline(p2, sort2);
		getline(p1, result1);
		getline(p2, result2);
		if (result1 != result2) {
			cmp = true;
			p3 << "test " << test << " Failed!" << endl;
			p3 << "Your answer:" << endl;
			p3 << number1 << endl << sort1 << endl << result1 << endl;
			p3 << "expected answer:" << endl;
			p3 << number2 << endl << sort2 << endl << result2 << endl << endl;
			test++;
		} 
	}
	if (cmp == false) p3 << "Correct answer!" << endl;
	p1.close();
	p2.close();
	p3.close();
	return 0;
}