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
void nextPermutation(vector<int>& nums) {
        int large_i = -1,large_j;
        for(int i = 0; i < nums.size()-1;i++) if(nums[i]<nums[i+1]) large_i = i;
        if(large_i == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i = large_i+1;i<nums.size();i++) if(nums[large_i]<nums[i]) large_j = i; 
        
		iter_swap(nums.begin()+large_i,nums.begin()+large_j);
		reverse(nums.begin()+large_i+1,nums.end());
        for(auto x: nums) cout<<x<<" ";
        return;        
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
		nextPermutation(v);
	}
	return 0;
}
