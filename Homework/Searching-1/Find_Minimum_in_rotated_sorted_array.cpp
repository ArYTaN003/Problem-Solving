int findMin(vector<int> &nums)
{
    int l = 0, u = nums.size() - 1, mid;
    while (l < u)
    {
        mid = l + (u - l) / 2;
        // Go towards the side which is less
        if (nums[mid] < nums[u])
        {
            u = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return nums[l];
}