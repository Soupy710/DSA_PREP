//Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key. The task is to find the index of the given element key in the array A.
//Solution 1: Use binary search to find the pivoted element and then perform binary search on one of the subarrays (on the left of the pivot or right)
//SOlution 2 (efficient): Perform a single modified binary search shown below
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
int search(int a[],int l,int r,int k)
{
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(a[mid]==k) return mid;
		if(a[l]>a[mid])
		{
			if(k>a[mid] && k<=a[r]) l = mid+1;
			else r = mid-1;
		}
		else{
			if(k<a[mid] && k>=a[l]) r = mid -1;
			else l = mid+1;
		}
	}
	return -1;
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
		int a[n];
		for (int i = 0; i < n; i++) {
			cin>>a[i];
		}
		cout<<search(a,0,n-1,k)<<endl;
	}
	return 0;
}
