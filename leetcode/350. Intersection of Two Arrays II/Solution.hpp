#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      vector<int> result;
      vector<int> nums3 = nums2;
      for (auto i = 0; i < nums1.size(); ++i) {
        auto iter = find(nums3.begin(), nums3.end(), nums1[i]);
        if (iter != nums3.end()) {
          result.push_back(*iter);
          nums3.erase(iter);
        }
      }
      return result;
    }
};
