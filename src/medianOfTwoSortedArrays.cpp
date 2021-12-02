#include <cmath>
#include <iostream>

#include "medianOfTwoSortedArrays.hpp"

using namespace std;
vector<int> mergeSortedArrays(vector<int>& nums1, vector<int>& nums2){
    vector<int> res;
    unsigned int i = 0;
    unsigned int j = 0;
    while(res.size() != nums1.size() + nums2.size()){
        bool cond1 = i < nums1.size();
        bool cond2 = j < nums2.size();
        if(cond1 && cond2){
            if(nums1[i] <= nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        else if(cond1){ // j has overflowed
            res.push_back(nums1[i]);
            i++;
        }
        else{ // i has overflowed
            res.push_back(nums2[j]);
            j++;
        }
    }
    return res;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    vector<int> mergedArray = mergeSortedArrays(nums1, nums2);
    float half = mergedArray.size() / 2;
    if(mergedArray.size() % 2){
        // Odd
        return mergedArray[(int) floor(half)];
    }
    else{
        // Even
        int index = (int) half;
        return ((double) mergedArray[index - 1] + (double) mergedArray[index]) / 2;
    }
}