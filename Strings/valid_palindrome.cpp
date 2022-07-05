//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
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
bool isPalindrome(string s) {
    int l = 0,r = s.length()-1;
    while(l<=r)
    {
        while(l<=r && !isalnum(s[l])) l++;
        while(l<=r && !isalnum(s[r])) r--;
        if(l<=r) if(toupper(s[l])!=toupper(s[r])) return false;
        l++;
        r--;
    }
    return true;
}
int main()
{
	fast;
	ll t;
	cin >> t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<isPalindrome(s)<<endl;
	}
	return 0;
}
