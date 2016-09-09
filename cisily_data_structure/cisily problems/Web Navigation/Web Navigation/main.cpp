#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;
int main() {
	//fstream input("data.txt");
	stack<string> web_in;
	stack<string> web_out;
	web_in.push("http://www.acm.org/");
	while (true) {
		string command;
		//getline(input, command);
		getline(cin, command);
		if (command == "QUIT") break;
		if (command.length() > 4 && command != "FORWARD") {
			string URL = command.substr(6, command.length() - 6);
			cout << URL << endl;
			web_in.push(URL);
			while (!web_out.empty()) web_out.pop();
		}
		else if (command == "BACK") {
			if (web_in.size() != 1) {
				string URL = web_in.top();
				web_out.push(URL);
				web_in.pop();
				cout << web_in.top() << endl;
			}
			else
			{
				cout << "Ignored" << endl;
			}
			
		}
		else
		{
			if (web_out.size() != 0) {
				string URL = web_out.top();
				cout << URL << endl;
				web_out.pop();
				web_in.push(URL);
			}
			else
			{
				cout << "Ignored" << endl;
			}
		}
	}
	return 0;
}