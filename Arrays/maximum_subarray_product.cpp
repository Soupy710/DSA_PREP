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
int maxProduct(vector<int> &);
int main()
{
	fast;
	ll t;
	cin >> t;
	while(t--)
	{
		int n;
		cin>>n;
		std::vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin>>v[i];
		}
		cout<<maxProduct(v)<<endl;
	}
	return 0;
}
int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(),nums.end());
        int cur_min = 1,cur_max = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                cur_min = 1;
                cur_max = 1;
                continue;
            }
            int n = nums[i];
            int temp = cur_max;
            cur_max = max(n*cur_max,n*cur_min);
            cur_max = max(cur_max,nums[i]);
            cur_min = min(n*cur_min,n*temp);
            cur_min = min(cur_min,n);
            res = max(res,cur_max);
         }
        return res;
    }
