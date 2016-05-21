//Author : liuzekun
//Data   : 2016.05.21
//Des    : leetcode 1. Two Sum
//Summ   : Given an array of integers, return indices of the two numbers such that they add up to a specific target.
#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target) {
    int augend, addend;  //被加数 和 加数
    int* res = (int*)malloc(2*sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        augend = nums[i];
        for (int j = i + 1; j < numsSize; ++j) {
            addend = nums[j];
            if ((augend + addend) == target) {
                res[0] = i;
                res[1] = j;
                printf("[%d, %d]\n", res[0], res[1]);
                return res;
            }
        }
    }
    return NULL;
}

int main() {
    int inData[4] = {2, 7, 11, 15};
    int* p = twoSum(inData, 4, 9);
    free(p);
    return 0;
}
