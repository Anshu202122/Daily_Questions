//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        if(mat.empty()){
            return 0;
        }
        int m=mat.size(), n=mat[0].size(), days=0, total=0, cnt=0;
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=0){
                    total++;
                }
                if(mat[i][j]==2){
                    q.push({i, j});
                }
            }
        }
        int dx[4]={0, 0, 1, -1};
        int dy[4]={1, -1, 0, 0};
        while(!q.empty()){
            int k=q.size();
            cnt+=k;
            while(k--){
                int x=q.front().first, y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n || mat[nx][ny]!=1){
                        continue;
                    }
                    mat[nx][ny]=2;
                    q.push({nx, ny});
                }
            }
            if(!q.empty()){
                days++;
            }
        }
        return total==cnt?days:-1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends