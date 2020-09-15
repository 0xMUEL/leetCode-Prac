#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
using std::vector;

class Solution {
public:
    //what I am doing is first calculate the difference of each day,
    //then by adding all the positive profits
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int profit = 0;
        int tempDifference = 0;
        for(unsigned i = 0; i < prices.size() - 1; i++){
            tempDifference = prices[i+1]-prices[i];
            if(tempDifference > 0){
                profit += tempDifference;
            }
        }

        return profit;
    }
};