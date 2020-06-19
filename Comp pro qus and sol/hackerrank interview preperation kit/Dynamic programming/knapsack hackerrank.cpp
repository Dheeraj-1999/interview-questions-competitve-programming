// Given an array of integers and a target sum, determine the sum nearest to but not exceeding the target that can be created. To create the sum, use any element of your array zero or more times.

// For example, if
// and your target sum is , you might select or

// . In this case, you can arrive at exactly the target.

// Function Description

// Complete the unboundedKnapsack function in the editor below. It must return an integer that represents the sum nearest to without exceeding the target value.

// unboundedKnapsack has the following parameter(s):

//     k: an integer
//     arr: an array of integers

// Input Format

// The first line contains an integer

// , the number of test cases.

// Each of the next
// pairs of lines are as follows:
// - The first line contains two integers and , the length of and the target sum.
// - The second line contains space separated integers

// .

// Constraints


// Output Format

// Print the maximum sum for each test case which is as near as possible, but not exceeding, to the target sum on a separate line.

// Sample Input

// 2
// 3 12
// 1 6 9
// 5 9
// 3 4 4 4 8

// Sample Output

// 12
// 9

// Explanation

// In the first test case, one can pick {6, 6}. In the second, we can pick {3,3,3}.




#include<bits/stdc++.h>
using namespace std;

int knapSack(int* arr, int w, int n, int ans) {
    if(n ==0 or w <=0 ) {
        // cout << endl << " weight " << w << endl;
        return 0;
    }
    if(arr[0] > w)
    	return knapSack(arr+1, w, n-1, ans);
    // cout << "ans" << ans << "ansEnd" << endl;
    int opt1 = knapSack(arr, w-arr[0], n, ans+arr[0]); //include the number
    // cout << w  << " "<< n  << endl;
    int opt2 = knapSack(arr+1, w, n-1, ans); // exclude the number
    // cout << w  << " "<< n  << endl;
    return(max(opt1, opt2));

}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--) {
        int n, w;
        cin >> n >> w;
        int* arr = new int[n+1];
        
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        cout << endl << knapSack(arr, w, n, 0);
    }
    return 0;
}
