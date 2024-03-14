#include "sort.h"
#include<chrono>

/*修改排序数据*/
void data(std::vector<int>& nums) {
    nums = {92, 85, 74, 63, 12, 43, 59, 68, 37, 90, 81, 20, 58, 2, 44, 73, 
    79, 55, 10, 17, 66, 95, 3, 49, 38, 60, 16, 98, 32, 6, 28, 19, 89, 29, 
    47, 67, 56, 41, 50, 53, 62, 23, 80, 27, 7, 97, 35, 71, 36, 87, 57, 24, 
    78, 13, 69, 99, 22, 96, 15, 86, 64, 88, 83, 33, 52, 8, 75, 1, 77, 42, 84, 
    94, 5, 26, 11, 76, 54, 91, 30, 39, 25, 46, 40, 18, 21, 9, 45, 31, 61, 14, 
    51, 34, 70, 65, 4, 72, 82, 48, 93, 100, 0};
} 


enum selection{
    BubbleSort = 1,
    SelectionSort = 2,
    InsertionSort = 3,
    QuickSort = 4,
    MergeSort = 5,
    HeapSort = 6,
    CountingSort = 7,
    RadixSort = 8,
    BucketSort = 9
};




int main() {
    std::vector<int> nums;
    Sort s1;
    int sort_choose;

    bool flag = true;
    while (flag) {
        std::cout<<"请选择具体的排序算法："<<std::endl;
        std::cout<<"1:冒泡排序 2:选择排序 3插入排序 4快速排序 5归并排序 6堆排序 7计数排序 8基数排序 9桶排序 其他键退出"<<std::endl;
        data(nums);
        std::cin>>sort_choose;
        auto start = std::chrono::high_resolution_clock::now();
        switch (sort_choose)
        {
            case BubbleSort:
                s1.bubble_sort(nums);
                break;
            case SelectionSort:
                s1.selection_sort(nums);
                break;
            case InsertionSort:
                s1.insert_sort(nums);
                break;
            case QuickSort:
                s1.quick_sort(nums, 0, nums.size() - 1);
                break;
            case MergeSort:
                s1.merge_sort(nums, 0, nums.size() - 1);
                break;
            case HeapSort:
                s1.heap_sort(nums);
                break;
            case CountingSort:
                s1.count_sort(nums);
                break;
            case RadixSort:
                //s1.selection_sort(nums);
                break;
            case BucketSort:
                //s1.selection_sort(nums);
                break;
            default:
            {
                flag = false;
                std::cout<<"成功退出"<<std::endl;
                break;
            }
        }
        if (flag == false) break;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout<<"排序耗时: "<< duration.count() << "微秒" <<std::endl;
        for (auto it : nums) {
            std::cout<<it<<" ";
        }
        std::cout<<"\n\n_______________________________________________________________________________________________\n";
    }
    

    return 0;
}