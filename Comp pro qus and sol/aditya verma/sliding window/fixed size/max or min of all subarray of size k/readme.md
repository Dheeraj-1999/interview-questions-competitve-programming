
# Sliding Window Maximum (Maximum of all subarrays of size k)


### Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.
Examples : 
 

Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
Output: 3 3 4 5 5 5 6
Explanation: 
Maximum of 1, 2, 3 is 3
Maximum of 2, 3, 1 is 3
Maximum of 3, 1, 4 is 4
Maximum of 1, 4, 5 is 5
Maximum of 4, 5, 2 is 5 
Maximum of 5, 2, 3 is 5
Maximum of 2, 3, 6 is 6

Input: arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, K = 4 
Output: 10 10 10 15 15 90 90
Explanation:
Maximum of first 4 elements is 10, similarly for next 4 
elements (i.e from index 1 to 4) is 10, So the sequence 
generated is 10 10 10 15 15 90 90



Method 1: This is a simple method to solve the above problem.
 

    Approach: 
    The idea is very basic run a nested loop, the outer loop which will mark the starting point of the subarray of length k, the inner loop will run from the starting index to index+k, k elements from starting index and print the maximum element among these k elements. 
     
    Algorithm: 
        Create a nested loop, the outer loop from starting index to n – k th elements. The inner loop will run for k iterations.
        Create a variable to store the maximum of k elements traversed by the inner loop.
        Find the maximum of k elements traversed by the inner loop.
        Print the maximum element in every iteration of outer loop

    Algorithm 2: 

    - Create a deque to store k elements.
    - Run a loop and insert first k elements in the deque. Before inserting the element, check if the element - at the back of the queue is smaller than the current element , if it is so remove the element from the - - back of the deque, until all elements left in the deque are greater than the current element. Then - - - - insert the current element, at the back of the deque.
    - Now, run a loop from k to end of the array.
    - Print the front element of the deque.
    - Remove the element from the front of the queue if they are out of the current window.
    - Insert the next element in the deque. Before inserting the element, check if the element at the back of - the queue is smaller than the current element , if it is so remove the element from the back of the - - - deque, until all elements left in the deque are greater than the current element. Then insert the - - - - current element, at the back of the deque.
    - Print the maximum element of the last window.


[Tutorial](https://www.youtube.com/watch?v=39grPZtywyQ)