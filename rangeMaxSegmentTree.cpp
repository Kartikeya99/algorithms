#include<bits/stdc++.h>

using namespace std;

int arr[1000005];  //max size of array can be 10^6
int tree[4000005]={0};  //

void build(int n,int s,int e){
    if(s==e){
        tree[n] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    build(2*n+1,s,mid);
    build(2*n+2,mid+1,e);
    tree[n] = max(tree[2*n+1],tree[2*n+2]);
}

void update(int n,int s,int e,int ind,int val){
    if(s==e){
        tree[n] = val;
        return;
    }
    int mid = (s+e)/2;
    if(ind<=mid)
        update(2*n+1,s,mid,ind,val);
    else
        update(2*n+2,mid+1,e,ind,val);
    tree[n] = max(tree[2*n+1],tree[2*n+2]);
}

int query(int n,int s,int e,int l,int r){
    if(r<s || l>e)
        return 0;
    if(s>=l && e<=r)
        return tree[n];
    int mid = (s+e)/2;
    int le = query(2*n+1,s,mid,l,r);
    int ri = query(2*n+2,mid+1,e,l,r);
    return max(le,ri);
}

int main(){
	int n,q; //size of array and numer of queries
	cin >> n >> q;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	build(0,0,n-1);
	while(q--){
		int le,ri;  //we have to find max(arr[le],arr[le+1],...,arr[ri])
		cin >> le >> ri;
		cout << query(0,0,n-1,le,ri) << "\n";
	}
}
