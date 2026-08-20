class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        // vector<int>arr1 = {nums[0]};
        // vector<int>arr2 = {nums[1]};

        // for(int i=2;i<nums.size();i++){
        //     if(arr1.back()>arr2.back()){
        //         arr1.push_back(nums[i]);
        //     }
        //     else{
        //         arr2.push_back(nums[i]);
        //     }
        // }

        // approch 2

        vector<int>arr1;
        vector<int>arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int last1 = nums[0];
        int last2 = nums[1];

        int i=2;
        while(i<nums.size()){
            if(last1>last2){
                arr1.push_back(nums[i]);
                last1 = nums[i];
            }
            else{
                arr2.push_back(nums[i]);
                last2 = nums[i];
            }
            i++;
        }

        for(auto x : arr2){
            arr1.push_back(x);
        }
        return arr1;
    }
};