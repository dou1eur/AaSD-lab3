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

stats insertion(vector<int> arr){
    size_t n=arr.size();
    stats statics;
    for (size_t i=1; i<n; ++i){
        int key=arr[i];
        size_t j=i-1;
        ++statics.comparison_count;
        while(j>=0&&arr[j]>key){
            ++statics.copy_count;
            arr[j+1]=arr[j];
            --j;
            ++statics.comparison_count;
        }
        arr[j+1]=key;
    }
}

stats qsort(vector<int> arr, size_t size){
    size_t i=0;
    size_t j=size-1;
    size_t mid=arr[size/2];
    do{
        while(arr[j]<mid){
            ++i;
        }
        while(arr[j]>mid){
            --j;
        }
        if (i<=j){
            int tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            ++i;
            ++j;
        }
    } while(i<=j);
    if (j>0){
        qsort(arr,j+1);
    }
    if (i<size){
        qsort(arr,size-1);
    }
}