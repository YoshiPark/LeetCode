#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
          int width = right - left;
          int h = min(height[left], height[right]);
          int area = width * h;
          if (area > result) result = area;
          if (height[left] > height[right]) {
            right--;
          } else {
            left++;
          }
        }
        return result;
    }
};
