#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (!result.empty()) result.clear();
        if (!ans.empty()) ans.clear();
        if (candidates.size() == 0) return result;
        DFS(0,0,target,candidates);
        return result;
    }
    void DFS(int start, int sum, int target, vector<int>& candidates) {
      if (sum == target) {
        result.push_back(ans);
      }
      else if (sum > target) {
        return ;
      }
      else {
        for (int i = start; i < candidates.size(); ++i) {
          ans.push_back(candidates[i]);
          DFS(i, sum+candidates[i], target, candidates);
          ans.pop_back();
        }
      }
    }
};
