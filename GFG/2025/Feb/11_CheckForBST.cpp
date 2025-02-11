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
    bool isBST(Node *root)
    {
        vector<int> nums;
        inorder(root, nums);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};