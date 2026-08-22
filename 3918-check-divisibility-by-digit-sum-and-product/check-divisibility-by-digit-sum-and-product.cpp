class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mul = 1;
        int nn = n;
        while(nn){
            int firstD;
            firstD = nn%10; 
            sum += firstD;
            mul *= firstD;
            nn = nn/10;
        }

        return n%(sum+mul)==0;
    }
};