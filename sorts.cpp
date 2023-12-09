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
    //cout<<"In insert"<<endl;
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

void quick_sort(std::vector<int>& arr, int left, int right, stats& s) {
    int i = left, j = right;
    int main = arr[left];
    while (i <= j) {
        while (arr[i] < main) {
            s.comparison_count++;
            i++;
        }
        while (arr[j] > main) {
            s.comparison_count++;
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;

            s.copy_count += 1;
        }
    }

    if (left < j)
        quick_sort(arr, left, j, s);
    if (i < right)
        quick_sort(arr, i, right, s);
}

stats quick_sort(std::vector<int>& arr, int size) {
    stats statistics;
    if (size<2){
        return statistics;
    }
    quick_sort(arr, 0, size - 1, statistics);
    return statistics;
}

stats merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right, stats& statistics) {
    size_t left_size = left.size();
    size_t right_size = right.size();
    size_t i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        statistics.comparison_count++;
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            ++i;
        } else {
            arr[k] = right[j];
            ++j;
        }
        statistics.copy_count++;
        ++k;
    }
    while (i < left_size) {
        arr[k] = left[i];
        ++i;
        statistics.copy_count++;
        ++k;
    }

    while (j < right_size) {
        arr[k] = right[j];
        ++j;
        statistics.copy_count++;
        ++k;
    }
    return statistics;
}

stats merge_sort(std::vector<int>& arr) {
    size_t size = arr.size();
    stats statistics;
    if (size < 2) {
        return statistics;
    }
    size_t mid = size / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());
    statistics = merge_sort(left);
    statistics = merge_sort(right);
    merge(arr, left, right, statistics);
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

