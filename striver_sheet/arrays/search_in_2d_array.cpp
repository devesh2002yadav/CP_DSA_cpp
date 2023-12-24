// 1) binary search on each row vector of matrix 

bool bins(vector<int> arr, int target)
{
    int n=arr.size();
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int mid=(right+left)/2;
        if(arr[mid]==target)
        {
            return true;
        }
        else if(arr[mid]<target)
        {
            left=mid+1;
        }
        else if(arr[mid]>target)
        {
            right=mid-1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& mat, int target) 
{
    int n=mat.size();
    int m=mat[0].size();
    vector<int> arr;
    for(int i=0; i<n; i++)
    {
        if(mat[i][0]<=target&&mat[i][m-1]>=target)
        {
            return bins(mat[i], target);
        }
    }
    return false; 
}

// 2) binary search on directly 2d matrix by reassigning the row and column values

/*


bool searchMatrix(vector<vector<int>>& mat, int target) 
{
    int n=mat.size();
    int m=mat[0].size();
    int left=0;
    int right=m*n-1;
    while(left<=right)
    {
        int mid=(right+left)/2;
        int row=mid/m; int col=mid%m;
        if(mat[row][col]==target)
        {
            return true;
        }
        else if(mat[row][col]<target)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return false; 
}

*/

