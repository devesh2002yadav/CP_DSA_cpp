#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
	int n=a.size();
	int m=b.size();
	int left=n-1;
	int right=0;
	while(left>=0&&right<=m-1)
	{
		if(a[left]>b[right])
		{
			swap(a[left], b[right]);
			left--; right++;
		}
		if(a[left]<=b[right])
		{
			break;
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}