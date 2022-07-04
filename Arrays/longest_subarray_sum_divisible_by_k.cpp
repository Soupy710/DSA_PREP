//The problem is to find the longest subarray’s length with the sum of the elements divisible by the given value k.
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
int longSubarrWthSumDivByK(int arr[], int n, int k)
{
	map<int,int> mp;
	int su = 0;
	int le = 0;
	for (int i = 0; i < n; ++i) {
		su+=arr[i];
		int x = ((su%k) + k)%k;
		if(x == 0) {
			le = i+1;
		}
		else if(mp.find(x)==mp.end()) mp[x] =i;
		else le = max(le,i-mp.find(x)->S);
	}
	return le;
}
int main()
{
	fast	
	int n,k;
	cin>>n>>k;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	cout<<longSubarrWthSumDivByK(a,n,k)<<endl;
	return 0;
}
