#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, b;
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a.find(b) != string::npos) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
