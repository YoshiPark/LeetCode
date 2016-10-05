#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int num, weight;
    int f[1000000] = {0};
    vector<int> W;
    vector<int> P;
    W.push_back(0);
    P.push_back(0);
    cin >> num;
    cin >> weight;
    for (auto i = 0; i < num; ++i) {
      int w, p;
      cin >> w;
      cin >> p;
      W.push_back(w);
      P.push_back(p);
    }
    for (auto i = 1; i <= num; ++i) {
      for (auto j = weight; j >= 0; --j) {
        if(j >= W[i]) f[j] = max(f[j], f[j - W[i]]+P[i]);
      }
    }
    cout << f[weight] << endl;
    return 0;
}
