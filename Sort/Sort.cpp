//
// Created by yaquan.zhou on 2021/5/7.
//

#include "Sort.h"

void Sort::heapSort(vector<int> &input) {
    //初始化最大堆
    for (int i = input.size() / 2 - 1; i >= 0; i--) {
        modifyHeap(input, input.size(), i);
    }
    //堆顶放于堆尾
    for (int i = input.size() - 1; i >= 1; i--) {
        swap(input, 0, i);
        modifyHeap(input, i, 0);
    }
}

void Sort::modifyHeap(vector<int> &input, int len, int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int maxIndex = index;
    if (left < len && input[left] > input[maxIndex]) maxIndex = left;
    if (right < len && input[right] > input[maxIndex]) maxIndex = right;
    if (index != maxIndex) {
        swap(input, index, maxIndex);
        modifyHeap(input, len, maxIndex);
    }
}

void Sort::quickSort(vector<int> &input, int l, int r) {
    if (l >= r) {
        return;
    }
    int left = l, right = r;
    int base = input[l];
    while (left < right) {
        while (left < right && input[right] >= base) {
            right--;
        }
        if (left < right) {
            input[left] = input[right];
        }
        while (left < right && input[left] <= base) {
            left++;
        }
        if (left < right) {
            input[right] = input[left];
        }
    }
    input[left] = base;
    quickSort(input, l, left - 1);
    quickSort(input, left + 1, r);
}

void Sort::swap(vector<int> &input, int i, int j) {
    int tmp = input[j];
    input[j] = input[i];
    input[i] = tmp;
}

int Sort::findKthLargest(vector<int> &nums, int k) {
    this->heapSort(nums);
//        for (auto i:nums)cout << i << "\t";
    return nums.at(nums.size() - k);
}