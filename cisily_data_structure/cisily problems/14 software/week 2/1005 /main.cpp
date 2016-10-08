#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
bool a[170] = {false};
int com;
void DFS(int start, pair<int, int> temp, vector<pair<int, int> > & nums, int & result) {
    bool is_conflict = false;
    for (int i = temp.first - 1; i < temp.second; ++i) {
      if (a[i] == true) {
        is_conflict = true;
        break;
      }
    }
    if (!is_conflict) {
      for (int i = temp.first - 1; i < temp.second; ++i) a[i] = true;
      com++;
      result = max(result, com);
    } else {
      return;
    }
    for (int i = start; i < nums.size() - 1; ++i) {
      DFS(i+1, nums[i+1], nums, result);
    }
    for (int i = temp.first - 1; i < temp.second; ++i) a[i] = false;
    com--;
}
int F(vector<pair<int, int> > & nums) {
    for (int i = 0; i < 170; ++i) a[i] = false;
    int result = 0;
    com = 0;
    if (nums.size() == 0) return result;
    pair<int, int> temp(0, 0);
    DFS(0, temp, nums, result);
    return result - 1;
}

int main() {
    freopen("Data.in", "r", stdin);
    int test;
    scanf("%d", &test);
    while (test--) {
        vector<pair<int, int> > time_vec;
        time_vec.push_back(pair<int, int>(0, 0));
        int times;
        scanf("%d", &times);
        while (times--) {
          pair<int, int> time_interval;
          int fir, sec;
          scanf("%d", &fir);
          scanf("%d", &sec);
          time_vec.push_back(pair<int, int>(fir, sec));
        }
        printf("%d\n", F(time_vec));
    }
    return 0;
}
