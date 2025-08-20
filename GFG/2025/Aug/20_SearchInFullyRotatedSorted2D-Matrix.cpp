class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int x)
    {
        int n = mat.size(), m = mat[0].size();
        long long l = 0, r = n * m - 1;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            long long row = mid / m, col = mid % m;
            long low = mat[l / m][l % m], high = mat[r / m][r % m];
            if (mat[row][col] == x)
            {
                return true;
            }
            if (low <= mat[row][col])
            {
                if (low <= x && x < mat[row][col])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (mat[row][col] < x && x <= high)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};