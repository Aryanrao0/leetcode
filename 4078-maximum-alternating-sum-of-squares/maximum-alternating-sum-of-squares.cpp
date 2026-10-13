class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            nums[i] *= nums[i];
        }

        sort(nums.begin(),nums.end());

        long long sub = 0;
        long long add = 0;

        for(int i=0;i<n;i++){
            if(i<n/2){
                sub += nums[i];
            }
            else{
                add += nums[i];
            }
        }

        return add-sub;

    }
};