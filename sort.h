#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <iostream>
#include <vector>
#include <algorithm>

class Sort{
public:
    /*冒泡排序：
        原理：比较相邻的元素，如果他们的顺序错误就交换他们，直到没有需要交换的元素为止
        时间复杂度：O(N^2)
        适用场景：不适合大规模数据排序，但是时间复杂度稳定*/
    void bubble_sort(std::vector<int>& nums) {
        int n = nums.size();
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            flag = false;
            // 每次将一个最大值移动到对应的位置
            for (int j = 0; j < n - i - 1; ++j) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    flag = true;
                }
            } 
            //若一次循环中没有发生元素交换，说明已经正确排序，无需继续遍历
            if (flag == false) 
                break;
        }
    }

    /*选择排序：
        原理：每次选择数组中最小的元素放在排好序的部分，直到结束
        时间复杂度：O(N*2)
        适用场景：比冒泡排序稍微快点*/
    void selection_sort(std::vector<int>& nums) {
        int n = nums.size();
        int min_index = 0;
        for (int i = 0; i < n; ++i) {
            min_index = i;
            for (int j = min_index; j < n; ++j) {
                min_index = nums[j] < nums[min_index] ? j : min_index;
            }
            std::swap(nums[min_index], nums[i]);
        }
    }

    /*插入排序：
        原理：将未排序的部分选一个元素插入已排序的部分
        时间复杂度：O(N^2)
        适用场景：比选择排序也快点，尤其是数组大都有序的情况下*/
    void insert_sort(std::vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int key = nums[i];
            int j = n - 1;
            while (j >= 0 && key < nums[j]) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;
        }
    }

    /*快速排序：
        原理：选择一个基准元素，将小于基准的元素放到基准的左侧，大于基准的元素放到右侧，然后对左右两侧的子数组进行递归排序。
        时间复杂度：O(NlogN) 最坏O(N)
        适用场景：使用大量数据，但要小心递归过多爆栈*/
    int partition(std::vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (nums[j] <= pivot) {
                i++;
                std::swap(nums[j], nums[i]);
            }
        }
        std::swap(nums[i + 1], nums[high]);
        return i + 1;
    }
    void quick_sort(std::vector<int>& nums, int low, int high) {
        if (low < high) {
            int mid = partition(nums, low, high);
            quick_sort(nums, low, mid - 1);
            quick_sort(nums, mid + 1, high);
        }
    }

    /*归并排序：
        原理：将数组分成两个子数组，分别对它们进行排序，然后将已排序的子数组合并成一个新的已排序数组。
        时间复杂度：O(NlogN)
        适用场景：是稳定的排序，大多数情况下性能好*/
    void merge(std::vector<int>& nums, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        
        std::vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; ++i)
            L[i] = nums[low + i];
        for (int j = 0; j < n2; ++j)
            R[j] = nums[mid + j + 1];

        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                nums[k] = L[i];
                i++;
            } else {
                nums[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            nums[k] = L[i];
            k++;
            i++;
        }
        while (j < n2) {
            nums[k] = R[j];
            k++;
            j++;
        }
    }
    void merge_sort(std::vector<int>& nums, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            merge_sort(nums, low, mid);
            merge_sort(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }

    /*堆排序：
        原理：利用堆的数据结构进行排序。将待排序的数组构建成一个最大堆（或最小堆），然后逐步将堆顶的元素与堆尾元素交换并调整堆，直到整个数组排序完成。
        时间复杂度：O(NlogN)
        适用场景：不稳定，会破坏相对位置*/
    void heapify(std::vector<int>& nums, int heapSize, int i) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int largest = i;

        if (left < heapSize && nums[left] > nums[largest])
            largest = left;
        if (right < heapSize && nums[right] > nums[largest])
            largest = right;

        if (largest != i) {
            std::swap(nums[i], nums[largest]);
            heapify(nums, heapSize, largest);
        }
    }
    void heap_sort(std::vector<int>& nums) {
        int heapSize = nums.size();

        for (int i = heapSize / 2 - 1; i >=0; --i) {
            heapify(nums, heapSize, i);
        }

        for (int i = heapSize - 1; i >= 0; --i) {
            std::swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }

    /*计数排序：
        原理：统计数组中每个元素出现的次数，然后根据元素的值将其放置到正确的位置，适用于元素范围较小且知道范围的情况。
        时间复杂度：N(N + K)，N是待排序数组的大小 k是待排序数组的取值范围
        适用场景：稳定排序，适用排序元素取值范围较小的情况*/
    void count_sort(std::vector<int>& nums) {
        int max_val = *std::max_element(nums.begin(), nums.end());
        int min_val = *std::min_element(nums.begin(), nums.end());
        int range = max_val - min_val + 1;
        
        int n = nums.size();
        std::vector<int> count(range), output(n);
    
        // 每个元素出现的个数
        for (int i = 0; i < n; ++i) {
            count[nums[i] - min_val]++;
        }

        // 元素累计出现的个数
        for (int i = 1; i < range; ++i) {
            count[i] += count[i - 1];
        }
        // 根据累计元素的位置获得输出数组
        for (int i = n - 1; i >= 0; --i) {
            output[count[nums[i] - min_val] - 1] = nums[i];
            count[nums[i] - min_val]--;
        }
        for (int i = 0; i < n; ++i) {
            nums[i] = output[i];
        }

    }
};
#endif
