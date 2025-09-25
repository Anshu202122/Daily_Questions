class Solution {
  public:
    vector<string> generateBinary(int n) {
        vector<string> ans;
        queue<string> q;
        int cnt=0;
        q.push("1");
        while(cnt<n){
            string s=q.front();
            q.pop();
            ans.push_back(s);
            cnt++;
            if(cnt==n){
                break;
            }
            q.push(s+'0');
            q.push(s+'1');
        }
        return ans;
    }
};
