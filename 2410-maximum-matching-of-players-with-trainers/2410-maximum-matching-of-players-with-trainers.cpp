class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int matching = 0;
        int ability = 0;

        while(matching < players.size() && ability < trainers.size()){
            if(players[matching] <= trainers[ability]){
                matching++;
            }
            ability++;
        }
        return matching;
    }
};