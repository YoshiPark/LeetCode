#include <string>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cow = 0;
        int num[10] = {0};
        for (auto i = 0; i < secret.length(); ++i) {
          if (secret[i] == guess[i]) {
            bulls++;
          } else {
            num[guess[i] - '0']++;
          }
        }
        for (auto i = 0; i < secret.length(); ++i) {
          if (secret[i] != guess[i] && num[guess[i] - '0'] > 0) {
            num[guess[i] - '0']--;
            cow++;
          }
        }
        char result[20];
        sprintf(result, "%dA%dB", bulls, cow);
        return result;
    }
};
