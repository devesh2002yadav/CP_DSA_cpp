class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int> mp;
    int fmax = 0, nmax, ln = barcodes.size();
    for (int n:barcodes) 
    {
        mp[n]++;
        if (mp[n] > fmax)
            fmax++, nmax = n;
    }
    mp.erase(nmax);
    vector<int> res(ln);
    int i = 0;
    for (; i < 2 * fmax; i+=2) res[i] = nmax;
    for (auto p:mp)
    {
        for (int j = 0; j < p.second; j++, i+=2)
        {
            if (i >= ln) i = 1;
            res[i] = p.first;
        }
    }
    return res;
}
};