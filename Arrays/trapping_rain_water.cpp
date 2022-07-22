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
int trap(vector<int>& height) {
	stack<int> s;
	int res = 0;
	for(int i=0;i<height.size();i++)
	{
		while(!s.empty() && height[i]>height[s.top()])
		{
			int t = height[s.top()];
			s.pop();
			if(s.empty()) continue;
			int min_height = min(height[i],height[s.top()]) - t;
			res+=min_height*(i-s.top()-1);
		}
		s.push(i);
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
		int n;
		cin>>n;
		vector<int> v(n);
		int i=0;
		while(n--){cin>>v[i];i++;}
		cout<<trap(v)<<endl;

		
	}
	return 0;
}
