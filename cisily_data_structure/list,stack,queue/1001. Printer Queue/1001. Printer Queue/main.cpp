#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
class queue {
private:
	int position;
	int priority;

public:
	queue() : position(0), priority(0) {}
	queue(int _position, int _priority) {
		position = _position;
		priority = _priority;
	}
	~queue() {}
	int getposition() { return position; }
	int getpriority() { return priority; }
	void setpriority(int _priority) { priority = _priority; }
	void setposition(int _position) { position = _position; }
};
bool sort_well(std::vector<class queue> & other) {
	for (std::vector<class queue>::iterator iter = other.begin();
		iter != other.end(); ++iter) {
		if (other[0].getpriority() < iter->getpriority())
			return false;
	}
	return true;
}
void sort_job(std::vector<class queue> & other) {
	while (sort_well(other) == false) {
		queue top = other.front();
		for (int i = 1; i < other.size(); ++i) {
			if (other[i].getpriority() > other[0].getpriority()) {
				other.push_back(top);
				other.erase(other.begin());
				break;
			}
		}
	}
}
int main() {
	int test;
	cin >> test;
	while (test--) {
		std::vector<class queue> job;
		int num, myposition;
		cin >> num >> myposition;
		int pos = 0;
		while (num--) {
			int priority;
			cin >> priority;
			queue temp(pos++, priority);
			job.push_back(temp);
		}
		int flag = 0;
		int count = 0;
		while (flag == 0) {
			bool temp = sort_well(job);
			if (temp == true) {
				int top = job[0].getposition();
				if (top == myposition) {
					cout << count + 1 << endl;
					flag = 1;
				}
				if (top != myposition) {
					job.erase(job.begin());
					if (job.empty())
						flag = 1;
					count++;
				}
			}
			else {
				sort_job(job);
			}
		}
	}

	return 0;
}