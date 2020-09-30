#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;
using std::vector;

class Solution {
public:
    vector<int> theNums;
    vector<int> original;
    Solution(vector<int>& nums) {
        theNums = nums;

        for(auto element: nums){
            original.push_back(element);
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        for(int i = 0; i < original.size(); i++){
            theNums[i] = original[i];
        }

        return theNums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(theNums.size() == 0){
            return theNums;
        }
        for(auto i = 0; i < theNums.size(); i++){
            int temp = theNums[i];
            int index = (rand() % (theNums.size() - i)) + i;
            theNums[i] = theNums[index];
            theNums[index] = temp;
        }
        return theNums;
    }

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */