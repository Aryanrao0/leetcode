class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss = "";
        string tt = "";

        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(ss.size()!=0){
                    ss.pop_back();
                }
                continue;
            }
            else{
                ss.push_back(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(tt.size()!=0){
                    tt.pop_back();
                }
                continue;
            }
            else{
                tt.push_back(t[i]);
            }
        }
        return ss==tt;

    }
};