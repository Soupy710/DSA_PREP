//Problem statement: Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
//Solution: sliding window. Go on increasing r-value until all characters of t is included in the window. then increase l-value and update minimum window ans if the sliding window still includes all characters of t. repeat the above once the window no longer includes all characters of t.
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
string minWindow(string s,string t)
{
	int l=0,r=0;
	int len = INT_MAX;
	string ans = "";
	int count = t.size();
	map<char,int> mp;
	for(auto c: t) mp[c]++;
	while(r<s.size())
	{
		if(mp[s[r]]>0) count--;
		mp[s[r]]--;
		while(count==0)
		{
			if(r-l+1<len) {
				ans = s.substr(l,r-l+1);
			    len = r-l+1;
			}
			mp[s[l]]++;
			if(mp[s[l]]>0) count++;
			l++;
		}
		r++;
	}
	return ans;
}
int main()
{
	fast;
	ll t;
	cin >> t;
	while(t--)
	{
		string s,t;
		cin>>s>>t;
		cout<<minWindow(s,t)<<endl;
	}
	return 0;
}
