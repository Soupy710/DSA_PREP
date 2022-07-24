int maxArea(vector<int>& height) {
	int i=0,j=height.size()-1,res=0,prev=0;
	while(i<j)
	{
		long int temp = min(height[i],height[j]);
		int x = temp*(j-i);
		res = max(res,x);
		if(height[i]==temp) i++;
		else j--;
		while(i<j && height[i]<temp) ++i;
		while(i<j && height[j]<temp) --j;
	}
	return res;
}
