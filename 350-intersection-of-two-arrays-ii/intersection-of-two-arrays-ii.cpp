class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int ,int> m;

        for(auto x : nums1){
            m[x]++;
        }

        vector<int> ans;

        for(auto y : nums2){
            if(m[y]>0){
                ans.push_back(y);
                m[y]--;
            }
        }

        return ans;
    }
};