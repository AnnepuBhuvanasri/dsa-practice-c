// Problem: Two Sum (LeetCode #1)
// Difficulty: Easy
// Approach: Brute Force - check every pair
// Time Complexity: O(n²)
// Space Complexity: O(1)


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result=(int*)malloc (2*sizeof(int));
    *returnSize=2;

    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                result[0]=i;
                result[1]=j;
                return result;
            }
        }
    }
    *returnSize=0;
    return result;


}
