//Find minimum and maximum element in an array 
//first method: brute force
//second method: tournament method (shown below)
//third method: find min max by taking in pairs (most efficient)


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

pair<long long,long long> getMinMaxfin(long long int arr[],int low,int high) {
    pair<long long, long long> p;
    if(high==low)
    {
        p.F = arr[low];
        p.second = arr[low];
        return p;
    }
    int mid = (high-low)/2;
    pair<long long, long long> p1 = getMinMaxfin(arr,low,low+mid);
    pair<long long,long long> p2 = getMinMaxfin(arr,low+mid+1,high);
    if(p1.first < p2.first) p.first = p1.first;
    else p.first = p2.first;
    if(p1.second>p2.second) p.second = p1.second;
    else p.second = p2.second;
    return p;
}

pair<long long, long long> getMinMax(long long int arr[], long long int n) {
    return getMinMaxfin(arr,0,n-1);
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for(ll i = 0; i < n; i++)
            cin >> arr[i];
        pair p = getMinMax(arr, n);
        cout << p.F << " " << p.S << endl;
    }
    return 0;
}