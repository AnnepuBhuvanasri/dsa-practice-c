// VALID ANAGRAM - LeetCode #242
// Problem: Given two strings s and t, return true if t is an anagram of s
// An anagram = same letters, same frequency, different order
// Approach: Count frequency of each letter using an array of size 26
// Time: O(n) - we loop through both strings once
// Space: O(1) - count array is always fixed at size 26

#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    
    // Step 1: Create a count array for all 26 letters
    // count[0] = 'a', count[1] = 'b', ... count[25] = 'z'
    // All start at 0 meaning we haven't seen any letters yet
    int count[26] = {0};
    
    // Step 2: Loop through s and add 1 for every letter
    // s[i] - 'a' converts letter to index (e.g. 'a'-'a'=0, 'b'-'a'=1)
    // '\0' is the end of string in C
    for(int i = 0; s[i] != '\0'; i++){
        count[s[i] - 'a']++;
    }
    
    // Step 3: Loop through t and subtract 1 for every letter
    for(int i = 0; t[i] != '\0'; i++){
        count[t[i] - 'a']--;
    }
    
    // Step 4: If all counts are 0, letters matched perfectly
    // If any count is not 0, s and t are not anagrams
    for(int i = 0; i < 26; i++){
        if(count[i] != 0)
            return false;
    }
    
    return true;
}
