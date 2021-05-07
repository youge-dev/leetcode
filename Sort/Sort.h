//
// Created by yaquan.zhou on 2021/5/7.
//

#ifndef DAILY_SORT_H
#define DAILY_SORT_H

#include "vector"

using namespace std;

class Sort {
public:
    /**
     * 堆排序
     * @param input
     */
    void heapSort(vector<int> &input);

    void modifyHeap(vector<int> &input, int len, int index);

    /**
     * 快速排序
     * @param input
     * @param l
     * @param r
     */
    void quickSort(vector<int> &input, int l, int r);

    /**
     * find 数组中第K大的数
     * @param nums
     * @param k
     * @return
     */
    int findKthLargest(vector<int> &nums, int k);

private:
    void swap(vector<int> &input, int i, int j);

};


#endif //DAILY_SORT_H
