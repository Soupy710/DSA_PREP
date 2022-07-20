    int findMin(vector<int>& a) {
        int l=0,r=a.size()-1;
        if(a.size()==1) return a[0];
        long long int mid;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(a[mid]>a[mid+1]) return a[mid+1];
            if(a[mid]>=a[r]) l = mid+1;
            else r = mid;
        }
        return a[mid];
    }
