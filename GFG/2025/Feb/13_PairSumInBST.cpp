class Solution
{
public:
    void inorder(Node *root, vector<int> &nums)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->data);
        inorder(root->right, nums);
    }
    bool findTarget(Node *root, int target)
    {
        vector<int> nums;
        inorder(root, nums);
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
            {
                return true;
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};