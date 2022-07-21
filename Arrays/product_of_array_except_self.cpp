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
void prod(vector<int> v)
{
	vector<int> res(v.size());
	res[0] =1;
	for(int i=1;i<res.size();i++)
	{
		res[i] = res[i-1]*v[i-1];
	}
	int p1 = 1;
	for(int i=v.size()-1;i>=0;i--)
	{
		res[i] = res[i]*p1;
		p1 = p1*v[i];
	}
	for(auto x:res) cout<<x<<" ";
	cout<<endl;
}
int main()
{
	fast;
	ll t;
	cin >> t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		prod(v);
	}
	return 0;
}
