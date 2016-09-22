class Solution {
public:
    bool isPowerOfThree(int n) {
      int i = 0;
      if(n<1) return false;
      int log = (int)(Math.log10(n)/Math.log10(3));
      if((int)Math.pow(3,log)==n) return true;
      return false;
    }
};
