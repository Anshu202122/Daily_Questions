class Solution
{
public:
    int startStation(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size(), ans = 0, curr = 0, gasSum = 0, costSum = 0;
        for (int i = 0; i < n; i++)
        {
            gasSum += gas[i];
            costSum += cost[i];
        }
        if (gasSum < costSum)
        {
            return -1;
        }
        for (int i = 0; i < n; i++)
        {
            curr += gas[i] - cost[i];
            if (curr < 0)
            {
                curr = 0;
                ans = i + 1;
            }
        }
        return ans;
    }
};