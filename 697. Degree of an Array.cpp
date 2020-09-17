#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using std::vector;

class Solution {
    //brute force(HUGE MEMORY USAGE)
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size() == 1){ //baseCase: there is only one element
            return 1;
        }
        //find the maximum number in the nums
        int maxNum = 0;
        for(int num: nums){
            maxNum = std::max(maxNum,num);
        }
        //count each element for the matching position
        int countArray[maxNum+1];
        //initialize the array element to 0;
        for(int i = 0; i < maxNum+1; i++){
            countArray[i] = 0;
        }
        int mode = 0;
        vector<int> majorityList;
        for(int num: nums){
            countArray[num] += 1;
            mode = std::max(mode,countArray[num]);
        }
        //find the mode number
        for(int num: nums){
            if(countArray[num] == mode){
                auto ret = std::find(majorityList.begin(),majorityList.end(),num);
                if(ret == majorityList.end()){
                    majorityList.push_back(num);
                }
            }
        }
        //find the minimum length for all the mode number
        int minDegree = nums.size();
        int tempCount = 0;//count until the mode
        int start = 0;
        int end = 0;
        bool initialized = false;
        for(int theModeNum: majorityList){
            for(int i = 0; i < nums.size(); i++){
                if(theModeNum == nums[i]){
                    if(start == 0 && !initialized){
                        start = i;
                        initialized = true;
                    }
                    tempCount++;
                    if(tempCount == mode){
                        end = i;
                        break;
                    }
                }
            }
            minDegree = std::min(end-start+1,minDegree);
            initialized = false;
            start = 0;
            end = 0;
            tempCount = 0;
        }
        return minDegree;
    }


};