class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a = nums.back();
        nums.pop_back();
        return (a-1)*(nums.back()-1);
    }
};