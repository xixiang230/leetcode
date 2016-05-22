//author    : liuzekun
//data      : 2016.05.22
//des       : leetcode 1 two sum
//summ      : Given an array of integers, return indices of the two numbers such that they add up to a specific target.
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j <nums.size(); j++) {
                    if (target - nums[i] == nums[j]) {
                        cout << "[" << i << ", " << j << "]" << endl;
                        return {i, j};
                    }
                }
            }
            return {-1, -1};
        }
};

int main(void) {
    Solution st;
    //vector<int> inData = {2, 7, 11 , 15};
    vector<int> inData = {-2, 7, 11 , 15};
    st.twoSum(inData, 13);
    return 0;
}
