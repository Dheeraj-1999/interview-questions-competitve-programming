#include<iostream>
using namespace std;
//checking if the number is a palindrome
int is_palin(int n){
   int rev = 0;
   for (int i = n; i > 0; i /= 10)
   rev = rev*10 + i%10;
   return (n==rev);
}
void countPal(int min, int max){
    int count = 0;
   for (int i = min; i <= max; i++)
   if (is_palin(i))
    count += 1;
    cout << count;
}
int main(){
   countPal(1000000, 2235959);
   return 0;
}