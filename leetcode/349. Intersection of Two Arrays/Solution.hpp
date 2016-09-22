#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> result;
        for (auto i = 0; i < nums1.size(); ++i) {
          auto iter = find(nums2.begin(), nums2.end(), nums1[i]);
          if (iter != nums2.end()) result.insert(*iter);
        }
        vector<int> temp;
        for (auto iter = result.begin(); iter != result.end(); ++iter) temp.push_back(*iter);
        return temp;
    }
};
