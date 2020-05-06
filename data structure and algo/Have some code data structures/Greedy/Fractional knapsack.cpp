#include<iostream>
#include<map>
#include<vector>


############## i have to change this code CODE NOT WORKING  CODE NOT WORKING CODE NOT WORKING CODE NOT WORKING ###################


using namespace std;
bool cmp(map<int>a,  map<int>b) 
{ 
    double r1 = (double)a->first / a->second; 
    double r2 = (double)b->first / b->second; 
    return r1 > r2; 
} 
double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
    //    sorting Item on basis of ratio 
    sort(arr, arr + n, cmp); 
  
    
    int curWeight = 0;  // Current weight in knapsack 
    double finalvalue = 0.0; // Result (value in Knapsack) 
  
    // Looping through all Items 
    for (int i = 0; i < n; i++) 
    { 
        // If adding Item won't overflow, add it completely 
        if (curWeight + arr[i].weight <= W) 
        { 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
  
        // If we can't add current Item, add fractional part of it 
        else
        { 
            int remain = W - curWeight; 
            finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
            break; 
        } 
    } 
  
    // Returning final value 
    return finalvalue; 
} 
int main(){
    map<int,int> m;
    map<int,int> :: iterator it;
    vector<int> profit(10);
	vector<int> weight(10);
    int n;

    cin>> n ;
    cout<<"enter profit array"<<endl;
    for(int i = 0; i<n;i++ ){
        cin>>profit[i];
    }
    cout<<"enter weight array"<<endl;
    for(int i = 0; i<n;i++ ){
        cin>>weight[i];
    }
    
    for(int i = 0; i< profit.size();i++){
        m[profit[i]] = weight[i];
    }
    for(it = m.begin(); it != m.end(); it++){
        cout<<endl<<it->first<<":"<<it->second;
    }
}
