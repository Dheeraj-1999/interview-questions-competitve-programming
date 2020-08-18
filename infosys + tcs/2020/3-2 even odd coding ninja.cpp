#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;

int calPower(int a,int b){
	if(b==0)
		return 1;
	int small=calPower(a,b/2);
	int ans=(small*small)%MOD;
	if(b%2==0)
		return ans;
	return (ans*a)%MOD;
}

int main(){
	int l,r,k;
	cin>>l>>r>>k;
	int fact[k+1];
	fact[0]=1;
	for(int i=1;i<=k;i++) fact[i]=(fact[i-1]*i)%MOD;
	int numbers=r-l+1;
	int even=numbers/2;
	if(l%2==0 && r%2==0) even++;
	int odd=numbers-even;
	int total=calPower(numbers,k);
	for(int i=1;i<=k;i+=2){
		int small=(calPower(odd,i)*calPower(even,k-i))%MOD;
		small=(small*fact[k])%MOD;
		small=((small*calPower(fact[k-i],MOD-2)%MOD)*calPower(fact[i],MOD-2))%MOD;
		total=(total-small+MOD)%MOD;
	}
	cout<<total;
	return 0;
}