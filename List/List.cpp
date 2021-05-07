//
// Created by yaquan.zhou on 2021/5/7.
//

#include "List.h"
#include "algorithm"

using namespace std;

void List::nextPermutation(vector<int> &nums) {
    int k = 0;
    int i = nums.size() - 1;
    for (; i >= 1; i--) {
        if (nums[i] > nums[i - 1]) {
            k = i - 1;  // 从后往前find 第一个相邻升序的元素对
            break;
        }
    }
    if (i == 0) {   //没找到
        reverse(nums.begin(), nums.end());
        return;
    }
    // [k+1,end) 必然降序，从后往前查找第一个大于k的数并交换，剩余元素升序排列，保证变大的幅度最小
    for (int j = nums.size() - 1; j >= k + 1; j--) {
        if (nums[j] > nums[k]) {
            swap(nums, j, k);
            reverse(nums.begin() + k + 1, nums.end());
            break;
        }
    }
}