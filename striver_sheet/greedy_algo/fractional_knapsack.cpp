#include <bits/stdc++.h> 

bool comparator(pair<int, int>&a, pair<int, int>&b)
{
    double x = (double)a.second/(double)a.first;
    double y = (double)b.second/(double)b.first;
    return x>y;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), comparator);
    int weight=0;
    double ans=0.0;
    for(int i=0; i<n; i++)
    {
        if(weight+items[i].first<=w)
        {
            weight+=items[i].first;
            ans+=(double)items[i].second;
        }
        else
        {
            double add=(double)(w-weight);
            ans+=add*((double)items[i].second/(double)items[i].first);
            break;
        }
    }
    return ans;
}