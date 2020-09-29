#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        vector<int> profitArray = {0};
        for(unsigned i = 0; i < prices.size() - 1; i++){
            profitArray.push_back(prices[i+1]-prices[i]);
        }
        unsigned begin = 0;
        unsigned end = profitArray.size() - 1;
        if (prices.size() == 0){ //the array is empty
            return 0;
        }
        return maxSubArrayHelper(profitArray, begin, end);
    }

    int maxSubArrayHelper(vector<int>& arr, unsigned low, unsigned high){
        if(low == high){ // base case: only one element 
            return arr[low];
        }else{
            unsigned mid = (low + high) / 2;
            int leftMax = maxSubArrayHelper(arr, low, mid);
            int rightMax = maxSubArrayHelper(arr, mid + 1, high);
            int crossMax = maxCrossSubArray(arr, low, mid, high);
            if(leftMax >= rightMax && leftMax >= crossMax){
                return leftMax;
            }else if(rightMax >= crossMax && rightMax >= leftMax){
                return rightMax;
            }else{
                return crossMax;
            }
        }
    }

    int maxCrossSubArray(vector<int>& arr, unsigned low, unsigned mid, unsigned high){
        int leftSum = 0;
        int rightSum = 0;
        int left_max = INT_MIN + 100;
        int right_max = INT_MIN + 100;

        for (int i = mid; i >= low; i--){
            if(i < 0){ //TODO: due to some unknown problem, I have to add this.
                break;
            }
            leftSum += arr[i];
            if(leftSum > left_max){
                left_max = leftSum;
            }
        }
        for (unsigned j = mid + 1; j <= high; j++){
            rightSum += arr[j];
            if(rightSum > right_max){
                right_max = rightSum;
            }
        }
        return left_max + right_max;
    }
};