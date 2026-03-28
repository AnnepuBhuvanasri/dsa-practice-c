// CONTAINER WITH MOST WATER - LeetCode #11
// Problem: Given heights of walls, find two walls that hold the most water
// Approach: Two Pointers - start from both ends, move shorter wall inward
// Formula: water = min(height[left], height[right]) * (right - left)
// Time: O(n) - single pass through the array
// Space: O(1) - no extra memory used

int maxArea(int* height, int heightSize) {
    
    // Step 1: Initialize two pointers at opposite ends
    // This gives us the maximum possible width to start with
    int left = 0;
    int right = heightSize - 1;
    
    // Step 2: Track the maximum water seen so far
    int maxWater = 0;
    
    // Step 3: Keep going until pointers meet
    while(left < right)
    {
        // Step 4: Find the shorter wall - water is always limited by shorter wall
        // Ternary operator: condition ? value_if_true : value_if_false
        int h = height[left] < height[right] ? height[left] : height[right];
        
        // Step 5: Calculate water = height x width
        // Width = distance between the two pointers
        int water = h * (right - left);
        
        // Step 6: Update maximum if current water is bigger
        if(water > maxWater)
            maxWater = water;
        
        // Step 7: Move the shorter wall inward
        // Moving the taller wall can never improve the result
        // Moving the shorter wall might find a taller one
        if(height[left] < height[right])
            left++;
        else if(height[left] > height[right])
            right--;
        else
            left++;  // when equal, move either pointer
    }
    
    // Step 8: Return the maximum water found
    return maxWater;
}
