#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the whatFlavors function below.
void whatFlavors(int* cost, int n, int money) {
    map<int, int> parlor;
    for(int i=1; i<=n; i++) {
        parlor[cost[i]] = i;
    }
    for(int i=1; i<=n; i++) {
        int diff = money - cost[i];
        // check if diff is present in map or not
        if(parlor[diff] > 0) and i != parlor[diff]) {
            cout << i << parlor[diff] << endl;
            break;
        } 
    }
}

//     map<int, int> :: iterator it;
//     for(it = parlor.begin(); it != parlor.end(); it++) {
//         cout << it->first << " " << it->second << endl;
//     //    if(parlor[money - a] > 0) {
//     //         // means elment is present
//     //         // cout <<"in: " << money <<" " << parlor[money - a] <<" "<< it->first << " " << it->second << endl;
//     //          cout <<""; //it->second <<" " << parlor[money - a] << endl;
//     //         break;
//     //     }
//     }


// void nsquare(int* arr, int n, int money) {
//     bool flag = true;
//     int* duplicate = new int[n+1];

//     for(int i=1; i<=n; i++)
//         duplicate[i] = arr[i];

//     sort(duplicate, duplicate+n);
//     for(int i=1; i<=n; i++) {
//         int diff = money - arr[i];
//         if(diff == 0) continue;

//         int key = binary_search(duplicate+i+1, duplicate+n, diff);

//         // for(int j=i+1; j<=n; j++) {
//         //     // check if diff in rest array;
//         //     if(arr[j] != diff)
//         //         continue;
//         //     cout << i << " " << j << endl;
//         //     flag = false;
//         //     break; 
//         // }
//         if(flag == false) break;
//     }
// }

int main()
{
    int t;
    cin >> t;

    while(t--) {
        int money;
        int n;
        cin >> money >> n;
        int* parlor = new int[n+1];
        for(int i=1; i<=n; i++) {
            cin >> parlor[i];
        }

        // nsquare(parlor, n, money);
        whatFlavors(parlor, n, money);
    }
}