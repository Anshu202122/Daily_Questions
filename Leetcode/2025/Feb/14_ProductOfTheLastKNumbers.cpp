class ProductOfNumbers
{
public:
    vector<int> nums;
    ProductOfNumbers() {}

    void add(int num) { nums.push_back(num); }

    int getProduct(int k)
    {
        int n = nums.size();
        int pdt = 1;
        int i = n - 1;
        while (i > ((n - 1) - k))
        {
            pdt *= nums[i];
            i--;
        }
        return pdt;
    }
};