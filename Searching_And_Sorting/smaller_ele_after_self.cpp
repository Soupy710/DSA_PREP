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
class Solution {
public:
    void mergeSort(vector<pair<int,int>>& v,int l,int r,map<int,int>& res)
    {
        if(l<r)
        {
            int mid = (l+r)/2;
            mergeSort(v,l,mid,res);
            mergeSort(v,mid+1,r,res);
            int left = l;
            int right = mid+1;
            vector<pair<int,int>> temp;
            while(left<=mid && right<=r)
            {
                if(v[left].second>v[right].second){
                   //cout<<v[left].first<<" "<<v[right].first<<endl;
                    res[v[left].first]+=1+abs(right-r);
                    temp.push_back(v[left]);
                    left++;
                }
                else{
                 // cout<<v[left].first<<" "<<v[right].first<<endl;
                    temp.push_back(v[right]);
                    right++;
                }
            }
            if(left>mid){
                while(right<=r){
                    temp.push_back(v[right]);
                    right++;
                }
            }
            else{
                while(left<=mid){
                    temp.push_back(v[left]);
                    left++;
                }
            }
            //for(auto x:temp) cout<<x<<endl;
              //  cout<<endl;
            for(int i=l;i<=r;i++) 
            {
                v[i] = temp[i-l];
            }
        }
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        map<int,int> mp;
        vector<pair<int,int>> fin;
        for(auto i=0;i<nums.size();i++) {
            fin.push_back(make_pair(i,nums[i]));
        }
       // for(auto x:fin) cout<<x.first;
        mergeSort(fin,0,nums.size()-1,mp);
        vector<int> res(nums.size());
        for(auto i=0;i<nums.size();i++) res[i] = mp[i];
        return res;
    }
    
};
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
