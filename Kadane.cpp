#include<bits/stdc++.h>

using namespace std;

#define ll long long int

ll maxSubArraySum(vector<ll> &a){
	ll ans=a[0],sum=0;
	for(int i=0;i<a.size();i++){
		sum += a[i];
		if(sum<0)
			sum=0;
		ans = max(ans,sum);
	}
	return ans;
}

int main(){
	int n;  //Size of array
	cin >> n;
	vector<ll> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	cout << maxSubArraySum(a);
	return 0;
}
