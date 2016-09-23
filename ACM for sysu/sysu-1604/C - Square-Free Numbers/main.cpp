#include <iostream>
#include <cmath>
#include <map>
#include <fstream>
using namespace std;
void primeFilte(bool* filter)  {

    for (int i=2; i<=1000000; i++)
        filter[i] = true;

    for (int i=2; i<=sqrt(1000000); i++)
    {
        if (filter[i])
        {
            int j = i*2;
            while (j<=1000000)
            {
                if (filter[j])
                    filter[j] = false;
                j+=i;
            }
        }
    }
}
int main() {
    // ofstream p1("result.data");
    bool *filter = new bool[1000000+1];
    primeFilte(filter);
    int num;
    cin >> num;
    // int total = 2;
    while (num--) {
      // int temp = total;
      int total;
      cin >> total;
      map<int, int> result;
      if (filter[total] == true) {
        // p1 << temp << ":1" << endl;
        cout << "1" << endl;
      } else {
        for (auto i = 2; i <= sqrt(total); ++i) {
          while (total % i == 0) {
            auto iter = result.find(i);
            if (iter == result.end()) {
              result.insert(pair<int,int> (i,1));
            } else {
              iter->second++;
            }
            total /= i;
          }
          if (total == 1) break;
        }
        int re = 0;
        for (auto iter = result.begin(); iter != result.end(); ++iter) {
          if (iter->second > re) re = iter->second;
        }
        // p1 << temp << ":" << re << endl;
        cout << re << endl;
      }
      // total = temp + 1;
    }
    delete []filter;
    // p1.close();
    return 0;
}
