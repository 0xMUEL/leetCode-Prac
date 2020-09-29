#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
using std::vector;

class Solution {
    //here is a O(n) algorithm
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 1){ //baseCase: there is only one element
            return nums;
        }
        vector<int> majorityList;
        int theMajority;
        int count = 0;
        bool alreadyChecked = false;
        for(unsigned i = 0; i < nums.size(); ++i){ //select a number
            theMajority = nums[i];
            count = 0;
            for(unsigned k = 0; k < i; ++k){//exclude the repeat case
                if(theMajority == nums[k]){
                    alreadyChecked = true;
                    break;
                }
            }
            if(alreadyChecked){
                alreadyChecked = false;
                continue;
            }

            for(unsigned j = 0; j < nums.size(); ++j){ //count the number through the array
                if(nums[j] == theMajority){
                    count++;
                }
            }
            if(count > nums.size()/3){//check if the number is the majority
                majorityList.push_back(theMajority);
            }
        }

        return majorityList;
    }


};