#include <fstream>
#include <string>
using namespace std;
int main(int argc, char const *argv[]) {
  ifstream p1("result.data");
  ifstream p2("standard.txt");
  ofstream p3("difference.data");
  while (!p1.eof() && !p2.eof()) {
    string s1,s2;
    getline(p1,s1);
    getline(p2,s2);
    if (s1 != s2) {
      p3 << "Your Answer:" << endl << s1 << endl;
      p3 << "Standard Answer: " << endl << s2 << endl;
    }
  }
  p1.close();
  p2.close();
  p3.close();
  return 0;
}
