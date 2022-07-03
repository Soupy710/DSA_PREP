//Problem statement - range query problem on an array. Given an array nums of n elements and q queries . Each query consists of two integers l and r . You task is to find the number of elements of nums[] in range [l,r] which occur atleast k times.€ý,€ý,
//Mo's algorithm - sort the queries based on r value of queries after dividing into blocks on root(n) based on L-value. Then use curr-l and curr-r to determine the sum for l,r range
//Effecient solution - compute prefix sum for all elements from 0 to n-1. For every query [L, R], we return value of preSum[R] â€“ preSum[L]. Here processing every query takes O(1) time.(only for sum queries)


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
int rootn;
bool compare(vector<int> x,vector<int> y)
{
	if(x[0]/rootn == y[0]/rootn) return x[1] < y[1];
	return x[0]/rootn < y[0]/rootn;
}
vector<int> solveQueries(vector<int> nums,vector<vector<int>> Queries,int k)
{
	vector<int> res(Queries.size());
	sort(Queries.begin(),Queries.end(),[](vector<int> x,vector<int> y){	if(x[0]/rootn == y[0]/rootn) return x[1] < y[1];
	return x[0]/rootn < y[0]/rootn;
});
	set<int> s;
	int mp[100004] = {0};
	int curr_l=0,curr_r = -1,l,r;
	for (auto i : Queries) {
		l = i[0];
		r = i[1];
		l--;
		r--;
		while(curr_r > r)
		{
			mp[nums[curr_r]]--;
				if(mp[nums[curr_r]]<k && s.find(nums[curr_r])!=s.end())
					s.erase(nums[curr_r]);
			curr_r--;
		}
	  while(curr_l < l){
			mp[nums[curr_l]]--;
			if(mp[nums[curr_l]]<k && s.find(nums[curr_l])!=s.end())
				s.erase(nums[curr_l]);
			curr_l++;
		}
		while(curr_l>l)	
		{
			curr_l--;
			mp[nums[curr_l]]++;
				if(mp[nums[curr_l]]>=k)
					s.insert(nums[curr_l]);
		}
		
		while(curr_r<r){
			curr_r++;
			mp[nums[curr_r]]++;
			if(mp[nums[curr_r]]>=k)
			{
				s.insert(nums[curr_r]);
			}
		} 
		res[i[2]] = s.size();
	}
	return res;
}
int main()
{
	fast;
	ll t;
	cin >> t;
	while(t--)
	{
		int n,q,k;
		cin>>n>>q>>k;
		vector<int> nums(n);
		rootn = sqrt(n);
		for (int i = 0; i < n; ++i) {
			cin>>nums[i];	
		}
		vector<vector<int>> Queries;
		for (int i = 0; i < q; ++i) {
			int l,r;
			cin>>l>>r;
			Queries.pb({l,r,i});
		}
		vector<int> ans = solveQueries(nums,Queries,k);
		for (auto i : ans) {
			cout<<i<<endl;
		}
	}
	return 0;
}
