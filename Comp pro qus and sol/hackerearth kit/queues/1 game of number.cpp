#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];

	for(int i=1; i<n+1; i++)
		cin >> arr[i];

	stack<int> s;
    int i, j , k;
	for(i=1; i<n+1; i++) {
		s.push(arr[i]);
        cout << arr[i] << " ";
		for(j=i+1; j<n+1; j++) {
            if(arr[i]  < arr[j]) {
                s.push(arr[j]);
                cout << arr[j] << " ";
            
                for(k=j+1; k<n+1; k++) {
                    if(arr[k] < arr[j]){
                        s.push(arr[k]);
                        cout << arr[k] << " ";
                        break;
                    }
                }
                break;
            }
		}
        cout << endl;
        // for(int i=0; i<s.size(); i++){
        //     cout << s.top();
        //     s.pop();
        // }
	}
}