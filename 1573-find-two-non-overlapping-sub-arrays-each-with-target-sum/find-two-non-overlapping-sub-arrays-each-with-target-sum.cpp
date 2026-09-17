class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        int i=0;
        int j=0;

        int currSum =  0;
        vector<int> minBestLinTillIdx(n, INT_MAX);

        int bestMinlen = INT_MAX;
        int result = INT_MAX;

        while(j<n){
            currSum += arr[j];

            while( i<j && currSum > target){
                currSum -= arr[i++];
            }

            if(currSum == target){
                int len = j-i+1;

                if(i>0 && minBestLinTillIdx[i-1]!=INT_MAX){
                    result  = min(result , len + minBestLinTillIdx[i-1]);
                }
                bestMinlen = min(bestMinlen,len);
            }
            minBestLinTillIdx[j]= bestMinlen;
            j++;
        }
        return result==INT_MAX ? -1 : result;
    }
};