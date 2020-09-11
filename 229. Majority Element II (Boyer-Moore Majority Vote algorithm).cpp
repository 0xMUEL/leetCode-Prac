#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
using std::vector;

class Solution {
    //Boyer-Moore Majority Vote algorithm
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 1){ //baseCase: there is only one element
            return nums;
        }
        vector<int> majorityList;
        int candidate1 = 0;
        int candidate2 = 1;
        int count1 = 0;
        int count2 = 0;
        for (auto theNum: nums){//Boyer-Moore Majority Vote algorithm
            if(theNum == candidate1){
                count1++;
            }else if (theNum == candidate2){
                count2++;
            }else if (count1 == 0){
                candidate1 = theNum;
                count1 = 1;
            }else if(count2 == 0){
                candidate2 = theNum;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        //double check the candidates
        for (auto theNum: nums){
            if(theNum == candidate1){
                count1++;
            }else if(theNum == candidate2){
                count2++;
            }
        }
        if(count1 > nums.size()/3){
            majorityList.push_back(candidate1);
        }
        if(count2 > nums.size()/3){
            majorityList.push_back(candidate2);
        }

        return majorityList;
    }


};