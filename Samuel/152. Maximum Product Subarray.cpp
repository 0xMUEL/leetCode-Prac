#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
using std::vector;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int r = nums[0];

        for(int i = 1, imax = r, imin = r; i < nums.size(); i++){
            //swap when nums[i] is negative, because multiply it 
            //makes a big number smaller, a small number bigger.
            if(nums[i] < 0){
                int temp = imax;
                imax = imin;
                imin = temp;
            }

            imax = std::max(nums[i],imax*nums[i]);
            imin = std::min(nums[i],imin*nums[i]);

            r = std::max(r,imax);
        }
        return r;
    }
};