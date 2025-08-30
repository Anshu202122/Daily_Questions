class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        if (n == 1)
        {
            return 0;
        }
        map<int, vector<int>> mp;
        vector<int> celeb;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1 && i != j)
                {
                    mp[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (mp.find(i) == mp.end())
            {
                celeb.push_back(i);
            }
        }
        if (celeb.size() != 1)
        {
            return -1;
        }
        int c = celeb[0], cnt = 0;
        for (auto &it : mp)
        {
            vector<int> temp = it.second;
            int i = 0, j = temp.size() - 1;
            while (i <= j)
            {
                int mid = (i + j) / 2;
                if (temp[mid] == c)
                {
                    cnt++;
                    break;
                }
                else if (temp[mid] < c)
                {
                    i = mid + 1;
                }
                else
                {
                    j = mid - 1;
                }
            }
        }
        if (cnt == n - 1)
        {
            return c;
        }
        return -1;
    }
};