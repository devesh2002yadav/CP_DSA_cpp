void subsum(int index, int sum, int n, vector<int> &num, vector<int> &ans)
{
	if(index==n)
	{
		ans.push_back(sum);
		return;
	}
	subsum(index+1,sum+num[index],n,num,ans);
	subsum(index+1,sum,n,num,ans);
}

vector<int> subsetSum(vector<int> &num)
{
	int n=num.size();
	vector<int> ans;
	subsum(0,0,n,num,ans);
	sort(ans.begin(), ans.end());
	return ans;
}


// TC - 2^N + 2^Nlog(2^N)