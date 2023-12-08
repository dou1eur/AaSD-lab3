#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>


using namespace std;

struct stats
{
    size_t comparison_count = 0;
    size_t copy_count = 0;
};

stats insertion(std::vector<int>& arr){
    size_t n=arr.size();
    stats statics;
    for (size_t i=1; i<n; ++i){
        for (size_t j=i; j>0; --j){
            ++statics.comparison_count;
            if (arr[j] < arr[j-1]){
                swap(arr[j],arr[j-1]);
                ++statics.copy_count;
            }
            else break;
        }
    }
    return statics;
}

stats qsort(std::vector<int>& arr, size_t size){
    stats statics;
    size_t i=0;
    size_t j=size-1;
    size_t mid=arr[size/2];
    while(i<=j){
        while(arr[i]<mid){
            statics.comparison_count++;
            ++i;
        }
        while(arr[j]>mid){
            statics.comparison_count++;
            --j;
        }
        if (i<j){
            int tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            ++i;
            ++j;
            statics.copy_count++;
        }
    } 
    if (j>0){
        qsort(arr,j+1);
    }
    if (i<size){
        qsort(arr,size-1);
    }
    return statics;
}

stats merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right, stats& statistics){
    size_t left_size = left.size();
    size_t right_size = right.size();
    size_t i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        statistics.comparison_count++;
        if (left[i] <= right[j]) {
            ++k;
            ++i;
            arr[k] = left[i];
        } else {
            ++k;
            ++j;
            arr[k] = right[j];
        }
        statistics.copy_count++;
    }
    while (i < left_size) {
        ++k;
        ++i;
        arr[k] = left[i];
        statistics.copy_count++;
    }

    while (j < right_size) {
        ++k;
        ++j;
        arr[k] = right[j];
        statistics.copy_count++;
    }
    return statistics;
}

stats merge_sort(std::vector<int>& arr){
    size_t size=arr.size();
    stats statistics;
    if(size<=1){
        return statistics;
    }
    size_t mid=size/2;
    std::vector<int> left(arr.begin(),arr.begin()+mid);
    std::vector<int> right(arr.begin()+mid,arr.end());
    statistics=merge_sort(left);
    statistics=merge_sort(right);
    merge(arr,left,right,statistics);
    return statistics;
}

std::vector<int> vector(int size){
    std::vector<int> arr;
    for(int i=0;i<size;++i){
        arr.push_back(i);
    }
    return arr;
}

std::vector<int> reverse_vector(int size){
    std::vector<int> arr;
    for(int i=size-1;i>=0;--i){
        arr.push_back(i);
    }
    return arr;
}

std::vector<int> random_vector(int size){
    std::vector<int> arr;
    for(int i=0;i<size;++i){
        arr.push_back(rand()%100);
    }
    return arr;
}

