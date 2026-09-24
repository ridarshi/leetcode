class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {

        int n = prices.size();

        int mini = INT_MAX;
        int secmini = INT_MAX;

        for (int i = 0; i < n; i++) {

            if (prices[i] < mini) {
                secmini = mini;
                mini = prices[i];
            }

            else if (prices[i] < secmini) {
                secmini = prices[i];
            }
        }

        int cost = mini + secmini;

        if (cost <= money) {
            return money - cost;
        }

        return money;
    }
};