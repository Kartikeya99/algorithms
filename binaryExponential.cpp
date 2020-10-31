#include<bits/stdc++.h>

using namespace std;

#define ll long long int

ll binaryExponential(ll n, ll p){
	ll ans = 1;
    while(p)
    {
        if(p&1)
            ans = ans*n;
        n = (n*n);
        p = (p>>1);
    }
    return ans;
}

int main(){
	ll n,p;
	cin >> n >> p;
	cout << binaryExponential(n,p);
	return 0;
}
