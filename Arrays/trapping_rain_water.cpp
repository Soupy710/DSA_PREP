//Solution 1: maintain two arrays 1. with the largest bar on the left for all elements 2. largest bar on the right
//Solution 2: stacks(shown below)
//Solution 3: two pointer approach(most efficient): Say we have indices i, j and a boundary of (left, right). where i is the left pointer and j is the right pointer.
//If the minimum is arr[left], we can say that i is bounded in one side by left and no matter whatever the values are in between (i, right), the rightmost boundary of i will at  least have height arr[right] which is the probable outermost boundary for i. 
//So the water height of water column at index i is arr[left] – arr[i] and we can increment i then.
//Similar things happen for j also.
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
