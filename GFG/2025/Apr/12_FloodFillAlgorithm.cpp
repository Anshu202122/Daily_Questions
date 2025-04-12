class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int m = image.size();
        int n = image[0].size();
        int color = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[sr][sc] = true;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, -1, 1};
            for (int t = 0; t < 4; t++)
            {
                int newX = x + dx[t];
                int newY = y + dy[t];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && visited[newX][newY] == false && image[newX][newY] == color)
                {
                    q.push({newX, newY});
                    image[newX][newY] = newColor;
                    visited[newX][newY] = true;
                }
            }
        }
        return image;
    }
};