//Solution 1: Use Maxheap
//Solution 2: modified quick sort
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007
int partition(vector<int> &v,int l,int r)
{
	int x = v[r],i = l,j=l;
	while(j<=r-1)
	{
		if(v[j]<=x){
			iter_swap(v.begin()+j,v.begin()+i);
			i++;
		}
		j++;
	}
	iter_swap(v.begin()+i,v.begin()+r);
	return i;
}
int helperk(vector<int> v,int l,int r,int k)
{
	int pos = partition(v,l,r);
	if(v.size()-k==pos) return v[pos];
	else if(pos<v.size()-k) return helperk(v,pos+1,r,k);
	else return helperk(v,l,pos-1,k);
}
int klargest(vector<int> v,int k)
{
	return helperk(v,0,v.size()-1,k);
}
int main()
{
	fast;
	ll t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin>>v[i];
		}
		cout<<klargest(v,k)<<endl;
	}
	return 0;
}
