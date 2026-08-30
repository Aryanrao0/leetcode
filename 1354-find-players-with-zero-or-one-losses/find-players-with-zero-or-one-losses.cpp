class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost_map;

        for (int i = 0; i < matches.size(); i++) {
            int loser = matches[i][1];

            lost_map[loser]++;
        }

        vector<int> NotLost;
        vector<int> LostOnes;

        for(int i=0;i<matches.size();i++){
            int winner = matches[i][0];
            int loser = matches[i][1];

            if(lost_map.find(winner)==lost_map.end()){ 
                NotLost.push_back(winner);
                lost_map[winner] = 2;
            }

            if(lost_map[loser]==1){
                LostOnes.push_back(loser);
            }
        }

        sort(LostOnes.begin(),LostOnes.end());
        sort(NotLost.begin(),NotLost.end());


        return {NotLost, LostOnes};
    }
};