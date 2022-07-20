/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.
*/
//Solution 1: use hash table
//Solution 2: use bitset (again O(n))
//Solution 3: Sorting:
//Solution 4: Put elements into their actual position i.e swap(arr[i],arr[arr[i]])
//Solution 5 below: calculate sum and sum of squares. Solve the two equations.
//Solution 6: Use XOR: take xor of all elements in array and all elements from 1..n. This will give x^y. then consider the rightmost set bit. Divide the array into two based on whether this bit is set or not.x and y will belong to one of these parts but both won't be in the same partition. Problem with this approach is that you won't know which is missing and which is repeating. 
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
void repeatedNumber(const vector<int> &v)
{
	long long int given_sum = 0,given_sum2 = 0;
	long long int actual_sum = v.size()*(v.size()+1),actual_sum2 = 0;
	actual_sum/=2;
	for(long long int i=0;i<=v.size();i++) actual_sum2+=i*i;
	for (auto i :v) {
		given_sum+=i;
		given_sum2+=i*i;
	}
	long long int diff1 = actual_sum - given_sum;
	long long int diff2 = actual_sum2 - given_sum2;
	long long int res = diff2/diff1 + diff1;
	res/=2;
	cout<<res-diff1<<" "<<res<<endl;
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
		for (int i = 0; i < n; i++) {
			cin>>v[i];
		}
		repeatedNumber(v);
	}
	return 0;
}
