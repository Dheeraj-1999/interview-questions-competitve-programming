
# Find maximum of minimum for every window size in a given array
Last Updated: 02-06-2020

Given an integer array of size n, find the maximum of the minimum’s of every window size in the array. Note that window size varies from 1 to n.

### Example:

    Input: arr[] = {10, 20, 30, 50, 10, 70, 30}
    Output: 70, 30, 20, 10, 10, 10, 10

    The first element in the output indicates the maximum of minimums of all
    windows of size 1.
    Minimums of windows of size 1 are {10}, {20}, {30}, {50}, {10},
    {70} and {30}. Maximum of these minimums is 70

    The second element in the output indicates the maximum of minimums of all
    windows of size 2.
    Minimums of windows of size 2 are {10}, {20}, {30}, {10}, {10},
    and {30}. Maximum of these minimums is 30