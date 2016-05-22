//author    : liuzekun
//data      : 2016.05.22
//des       : leetcode 1 two sum
//summ      : Given an array of integers, return indices of the two numbers such that they add up to a specific target.
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_set<int> num_set(nums.begin(), nums.end());
            int first = -1; 
            int second = -1;
            for(int i = 0; i < nums.size(); ++i) {
                int diff = target - nums[i];    
                if (num_set.find(diff) != num_set.end()) {
                    for (int j = i + 1; j < nums.size(); ++j) {
                        if (nums[j] == diff) {
                            first = i;
                            second = j;
                            break;
                        }
                    }
                }
            }
            cout << "[" << first << ", " << second << "]" << endl; 
            return {first, second};
        }
};

int main(void) {
    Solution st;
    //vector<int> inData = {2, 7, 11 , 15};
    vector<int> inData = {-2, 7, 11 , 15};
    //vector<int> inData = {3, 2, 4};
    st.twoSum(inData, 18);
    return 0;
}
