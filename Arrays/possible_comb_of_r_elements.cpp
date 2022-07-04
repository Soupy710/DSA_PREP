//Given an array of size n, generate and print all possible combinations of r elements in array. 
//Solution 1: below
//Solution 2: similar to subset sum problem - include an element and not include an element.
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
void recur_longest(vector<int> data,int n,vector<int> v,int start,int r)
{
	if(data.size()==r){
		for (auto i : data) {
			cout<<i<<" ";
		}
		cout<<endl;return;
	}
	for (int i = start; i < n; ++i) {
		data.pb(v[i]);
		recur_longest(data,n,v,i+1,r);
		data.pop_back();
	}
}
void longest_subarray(vector<int> v,int r)
{
	vector<int> data;
	recur_longest(data,v.size(),v,0,r);

}
int main()
{
	fast;
	int n,r;
	cin>>n>>r;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin>>v[i];
	}
	longest_subarray(v,r);	
	return 0;
}
