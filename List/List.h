//
// Created by yaquan.zhou on 2021/5/7.
//

#ifndef DAILY_LIST_H
#define DAILY_LIST_H

#include <iostream>
#include "vector"

using namespace std;

class List {
public:
    /**
     * 按照字典序的下一个排列
     * @param nums
     */
    void nextPermutation(vector<int> &nums);


    /**
     * 两数之和
     */
    vector<int> twoSum(vector<int> &input, int target);

    /**
     * 连续子数组的最大和
     */
    int maxSubArray(vector<int> &nums);

    /**
     * 三数之和
     */
    vector<vector<int>> threeSum(vector<int> &nums);

private:
    void swap(vector<int> &input, int i, int j) {
        int tmp = input[i];
        input[i] = input[j];
        input[j] = tmp;
    }
};


#endif //DAILY_LIST_H
