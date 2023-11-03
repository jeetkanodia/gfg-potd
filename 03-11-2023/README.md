# Pythagorean Triplet

## Given an array arr of n integers, write a function that returns true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a^2 + b^2 = c^2 , otherwise return false.

Input: <br>
N = 5 <br>
Arr[] = {3, 2, 4, 6, 5} <br>
Output: Yes <br>
Explanation: a=3, b=4, and c=5 forms a
pythagorean triplet.

Brute Force:
Form all the triplets <br>
TC - O(N^3) <br>
SC - O(1)

Better Approach:
store the squares in hashmap and iterate the array, similar to 2 sum <br>
TC - O(N^2) <br>
SC - O(N)

Better Approach:
3 sum approach: store the squares in hashmap and iterate the array, similar to 2 sum <br>
TC - O(N^2) <br>
SC - O(1)
