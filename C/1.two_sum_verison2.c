//Author : liuzekun
//Data   : 2016.05.21
//Des    : leetcode 1. Two Sum
//Summ   : Given an array of integers, return indices of the two numbers such that they add up to a specific target.
#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    if (numsSize < 2) {
        return NULL;
    }

    int min_num = nums[0];
    int max_num = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] < min_num) {
            min_num = nums[i];
        }
        if (nums[i] > max_num) {
            max_num = nums[i];
        }
    }
    
    int size = 8 * sizeof(int);
    int blocks = (max_num - min_num) / size + 1; 
    int* num_bitmap = (int*)calloc(blocks, size);  //位图，对应位置用于存储数字是否存在，1表示存在，0表示不存在
    int remainder = 0; 
    int quotient = 0;
    for (int i = 0; i < numsSize; ++i) {
       remainder = (nums[i] - min_num) % size; 
       quotient = (nums[i] - min_num) / size;
       num_bitmap[quotient] = num_bitmap[quotient] | (1 << remainder);
    }

    int* res = (int*)malloc(2*sizeof(int));
    int diff = 0;
    int addend_divid = 0;
    int addend_mod = 0;
    for (int i = 0; i < numsSize; ++i) {
        diff = target - nums [i];
        addend_mod = (diff - min_num) % size;
        addend_divid = (diff - min_num) / size;
        if (0 != (num_bitmap[addend_divid] & (1 <<addend_mod))) {
            res[0] = i;
            for(int j = i +1; j < numsSize; ++j) {
                if (diff == nums[j] && j != i) {
                    res[1] = j;
                    printf("[%d, %d]\n", res[0], res[1]);
                    return res;
                }
            }
        }
    }

    free(num_bitmap);
    return NULL;
}

int main() {
    //int inData[3] = {3, 2, 4};
    //int inData[4] = {2, 7, 11, 15};
    int inData[4] = {0, 4, 3, 0};
    //int inData[4] = {-3, 4, 3, 90};
    int* p = twoSum(inData, 4, 0);
    free(p);
    return 0;
}
