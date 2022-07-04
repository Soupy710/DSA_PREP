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
int maxSubArray(vector<int>& v)
{
	//kadane's algo
	int max_so_far=v[0],cur_max=v[0];
	for(int i=1;i<v.size();i++)
	{
		cur_max = max(v[i],v[i]+cur_max);
		max_so_far = max(cur_max,max_so_far);
	}
	return max_so_far;
	/* dp approach
	 * for(int i=1;i<n;i++){
	 *		dp[i] = max(v[i],v[i]+dp[i-1]);
	 * }
	 * return *max_element(dp.begin(),dp.end());
	 */
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
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin>>a[i];
		}
		cout<<maxSubArray(a)<<endl;
	}
	return 0;
}
