// TWO SUM II - LeetCode #167
// Problem: Given a sorted array, find two numbers that add up to target
// Return their indices (1-indexed, not 0-indexed)
// Approach: Two Pointers - use the sorted property to move pointers smartly
// Time: O(n) - we walk through the array once
// Space: O(1) - no extra memory used except result

#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    
    // Step 1: Allocate memory for result array (2 indices)
    int *result = (int*)malloc(2*sizeof(int));
    
    // Step 2: Tell LeetCode we are returning 2 numbers
    *returnSize = 2;
    
    // Step 3: Initialize two pointers
    // left starts at beginning, right starts at end
    int left = 0;
    int right = numbersSize - 1;
    
    // Step 4: Keep going until pointers meet
    while(left < right)
    {
        if(numbers[left] + numbers[right] > target)
        {
            // Sum too big → move right pointer down to get smaller number
            right--;
        }
        else if(numbers[left] + numbers[right] < target)
        {
            // Sum too small → move left pointer up to get bigger number
            left++;
        }
        else
        {
            // Sum matches target → found our answer!
            // +1 because LeetCode wants 1-indexed not 0-indexed
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        }
    }
    
    // Fallback return (will never reach here as problem guarantees one solution)
    return result;
}
