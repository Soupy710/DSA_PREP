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
int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
    }
    return 0;
}
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> res;
        int size = a.size();
        for(int i=0;i<a.size()-2;i++)
        {
            int temp = a[i];
            int left = i+1,right = size-1;
            
            while(left<right)
            {
                if(a[i]+a[left]+a[right]>0) right--;
                else if(a[i]+a[left]+a[right]<0) left++;
                else
                {
                    cout<<left<<" "<<right<<endl;
                    vector<int> temp{a[i],a[left],a[right]};
                    res.push_back(temp);
                    int t1 = left,t2=right;
                    while(left<right && a[t1]==a[left]) left++;
                    while(left<right && a[t2]==a[right]) right--;
                }

            }
            while(i+1<size && a[i]==a[i+1]) i++;
        }
        return res;
    }
};
