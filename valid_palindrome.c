// VALID PALINDROME - LeetCode #125
// Problem: Given a string, return true if it is a palindrome
// ignoring spaces, punctuation and uppercase letters
// Approach: Two Pointers - one at start, one at end, move towards each other
// Time: O(n) - we walk through the string once
// Space: O(1) - no extra memory used

#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    
    // Step 1: Initialize two pointers
    // left starts at beginning, right starts at end
    int left = 0;
    int right = strlen(s) - 1;
    
    // Step 2: Keep going until pointers meet in the middle
    while(left < right)
    {
        // Step 3: Skip non-alphanumeric characters (spaces, punctuation)
        // isalnum() returns true if character is a letter or number
        while(left < right && !isalnum(s[left]))
            left++;
        while(left < right && !isalnum(s[right]))
            right--;
        
        // Step 4: Compare characters at both pointers
        // tolower() converts to lowercase so 'A' and 'a' are treated the same
        if(tolower(s[left]) != tolower(s[right]))
            return false;  // characters don't match, not a palindrome
        
        // Step 5: Move pointers inward towards each other
        left++;
        right--;  // right goes DOWN not up!
    }
    
    // Step 6: All characters matched, it's a palindrome
    return true;
}
