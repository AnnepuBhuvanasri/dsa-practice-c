// CONTAINS DUPLICATE - LeetCode #217
// Problem: Return true if array has duplicates, false if all elements are distinct
// Approach: Sort the array, then check if any two adjacent elements are equal
// Time: O(n log n) for sorting
// Space: O(1) if we sort in-place

#include <stdlib.h>
#include <stdbool.h>

// Comparator function for qsort
// Tells qsort how to compare two integers in ascending order
int comparator(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    // Step 1: Sort the array so duplicates become adjacent
    qsort(nums, numsSize, sizeof(int), comparator);
    
    // Step 2: Walk through the sorted array
    // Use numsSize-1 as limit because we check nums[i+1]
    // If we went to numsSize, nums[i+1] would be out of bounds
    for(int i = 0; i < numsSize-1; i++){
        // Step 3: Check if current element equals next element
        // After sorting, duplicates are always neighbors
        if(nums[i] == nums[i+1]){
            return true;  // Found a duplicate, return immediately
        }
    }
    
    // Step 4: If loop completes, no duplicates found
    return false;
}
