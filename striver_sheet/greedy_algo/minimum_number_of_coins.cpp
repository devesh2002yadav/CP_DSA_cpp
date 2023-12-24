vector<int> MinimumCoins(int n)
{
  int ar[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
  vector<int> ans;
  for (int i = 0; i < 9; i++) 
  {
    while (n >= ar[i]) 
    {
      ans.push_back(ar[i]);
      n -= ar[i];
    }
  }
  return ans;
}