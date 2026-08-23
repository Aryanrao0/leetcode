class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;

        for(int x : nums1){
            st.insert(x);
        }

        vector<int> ans;
    
        for(int y : nums2){
            if(st.count(y)){
                ans.push_back(y);
                st.erase(y);
            }
        }

        return ans;
    }
};