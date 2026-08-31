class Solution {
public:
    int mirrorDistance(int n) {
        int f = n;
        long long rev = 0;
        while(f){
            rev = 10*rev+f%10;
            f = f/10;
        }

        long long ans = abs(rev - n);

        return ans;


        
    }
};