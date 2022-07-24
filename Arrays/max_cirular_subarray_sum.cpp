//max subarray sum = total array sum - sum of non-contributing elements
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
int kadane(int arr[],int n)
{
	int max_so_far = INT_MIN;
	int all_max = INT_MIN;
	for(int i=0;i<n;i++)
	{
		max_so_far = max(arr[i],arr[i]+max_so_far);
		cout<<max_so_far<<endl;
		if(max_so_far<0) max_so_far = 0; 
		all_max = max(max_so_far,all_max);
	}
	return all_max;
}
int solve(int arr[],int n)
{
	int withoutwrap = kadane(arr,n);
	int withwrap = 0;
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		arr[i] = -arr[i];
	}
	int x = kadane(arr,n);
	withwrap = sum + x;
	return max(withwrap,withoutwrap);
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
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		cout<<solve(a,n)<<endl;
	}
	return 0;
}
