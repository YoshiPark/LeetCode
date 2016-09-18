#include <algorithm>
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C-A) * (D-B) + (G-E) * (H-F);
        int overlap = 0;
        long wlimit,hlimit;
        wlimit = (long)min(C,G)-(long)max(A,E);
        hlimit = min(D,H)-max(B,F);
        if(wlimit >=0 && hlimit >= 0)
        {
            overlap = (min(C,G)-max(A,E))* (min(D,H)-max(B,F));
            return area - overlap;
        } else {
          return area;
        }
    }
};
