//Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
//1. Each student gets exactly one packet.
//2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.
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
long long findMinDiff(vector<int> a, int n, int m)
{
	int ans = INT_MAX;
	if(n<m) return -1;
	sort(a.begin(),a.end());
	for(int i=0;i<n-m+1;i++)
		if(a[i+m-1]-a[i] < ans) ans = a[i+m-1] - a[i];
	return ans;
}
int main()
{
	fast;
	ll t;
	cin >> t;
	while(t--)
	{
		int m,n;
		cin>>n>>m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin>>a[i];
		}
		cout<<findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
