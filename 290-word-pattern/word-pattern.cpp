class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;

        stringstream ss(s);
        string token;

        while (getline(ss, token, ' ')) {
            words.push_back(token);
        }

        int n = pattern.length();

        if (n != words.size())
            return false;

        unordered_map<string, char> mp;
        unordered_set<char> used;

        for (int i = 0; i < n; i++) {
            string word = words[i];
            char ch = pattern[i];

            if (mp.find(word) == mp.end()) {

                if (used.find(ch) != used.end())
                    return false;

                mp[word] = ch;
                used.insert(ch);
            }
            else {
                if (mp[word] != ch)
                    return false;
            }
        }

        return true;
    }
};