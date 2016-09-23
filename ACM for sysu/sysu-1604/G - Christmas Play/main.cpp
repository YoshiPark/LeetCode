#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int num;
    cin >> num;
    while (num--) {
      int total, select_num;
      cin >> total;
      cin >> select_num;
      if (select_num == 1) {
        for (auto i = 0; i < total; ++i) {
          long long int h;
          cin >> h;
        }
        cout << "0" << endl;
      } else {
        vector<long long int> height;
        for (auto i = 0; i < total; ++i) {
          long long int h;
          cin >> h;
          height.push_back(h);
        }
        sort(height.begin(), height.end());
        vector<long long int> diff;
        int size = height.size();
        for (auto i = 0; i <= size - select_num; ++i) {
          long long difference = height[i+select_num - 1] - height[i];
          diff.push_back(difference);
        }
        sort(diff.begin(),diff.end());
        cout << diff[0] << endl;
      }
    }
    return 0;
}
