#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*class Solution {
public:
	//ʹ��������ȵĻ��ݷ�
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> path;
		sort(nums.begin(), nums.end());
		result.push_back(path);
		dfs(nums, 0, path, result);
		return result;
	}
	void dfs(vector<int>& nums, int pos, vector<int> & path, vector<vector<int>> & result)
	{
		cout << endl << endl;
		cout << "DFS�ӵ�" << pos << "��λ�ý���" << endl;
		if (pos == nums.size()) {
			cout << "pos == nums.size()" << endl;
			cout << "DFS�˿��˵�" << pos << "������" << endl << endl << endl;
			return;
		}
			

		for (int i = pos; i<nums.size(); i++)
		{
			cout << "DFS�ӵ�" << pos << "��λ�ý����" << i << "��ѭ��" << endl;
			path.push_back(nums[i]);
			cout << "Path push_back" << nums[i] << endl;
			result.push_back(path);
			cout << "Result push_back path :" << endl;
			cout << "[";
			for (auto i = 0; i < path.size(); ++i) {
				cout << path[i];
				if (i != path.size() - 1) cout << ",";
			}
			cout << "]" << endl;
			dfs(nums, i + 1, path, result);
			int num = path.back();
			path.pop_back();
			cout << "Path pop_back" << num <<endl;
		}
		cout << "DFS�˿��˵�" << pos << "������" << endl << endl << endl;
	}

}; */
class Solution {
public:
	//ʹ��������ȵĻ��ݷ�
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> path;
		sort(nums.begin(), nums.end());
		result.push_back(path);
		dfs(nums, 0, path, result);
		return result;
	}
	void dfs(vector<int>& nums, int pos, vector<int> & path, vector<vector<int>> & result)
	{
		if (pos == nums.size())
			return;

		for (int i = pos; i<nums.size(); i++)
		{
			path.push_back(nums[i]);
			result.push_back(path);
			dfs(nums, i + 1, path, result);
			path.pop_back();
		}
	}

};
