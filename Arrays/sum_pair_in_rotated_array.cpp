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
bool sum_pair(vector<int> v,int x)
{
	int k=0;
	int n = v.size();
	for(;k<v.size()-1;k++) if(v[k]>v[k+1]) break;
	int i=(k+1)%n,j=k;
	while(i!=j)
	{
		if(v[i]+v[j]==x) return true;
		else if(v[i]+v[j]<x) i = (i+1)%n;
		else j = (j+n-1)%n;
	}
	return false;
}
int main()
{
	fast;
	ll t;
	cin >> t;
	while(t--)
	{
		int n,x;

		cin>>n>>x;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin>>v[i];
		}
		cout<<sum_pair(v,x)<<endl;
	}
	return 0;
}
