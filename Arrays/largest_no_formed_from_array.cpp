static bool myCompare(string s1,string s2)
{
	string x = s1.append(s2);
	string y = s2.append(s1);
	return x>y;
}
string printLargest(vector<string> &arr) {
	// code here
	sort(arr.begin(),arr.end(),myCompare);
	string s;
	for(auto x:arr) s+=x;
	return s;
}
