// 1) hashmap approach - to store freq and then see - TC_O(nlogn)

#include<map>
int majorityElement(vector<int> v) 
{
	map<int, int> freq;
	int n=v.size();
	for(int i=0; i<n; i++)
	{
        freq[v[i]]++;
	}
	for(auto x:freq)
	{
		if(x.second>n/2)
		{
			return x.first;
		}
	}
}

// 2) moore's voting algo - TC-O(n)

/*

#include<map>

int majorityElement(vector<int> v) 
{
	int cnt=1;
	int el=v[0];
	int n=v.size();
	for(int i=1; i<n; i++)
	{
        if(v[i]==el)
		{
			cnt++;
		}
		else cnt--;
		if(cnt==0)
		{
			el=v[i];
			cnt++;
		}
	}
	return el;
}

*/