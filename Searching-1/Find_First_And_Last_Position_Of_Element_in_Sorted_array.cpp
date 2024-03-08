vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans = {-1, -1};
    // ans[0] represents first occurence , ans[1] represents last occurence
    int l = 0, u = nums.size() - 1, mid;
    while (l <= u)
    {
        mid = l + (u - l) / 2;
        if (nums[mid] >= target)
        {
            if (nums[mid] == target)
            {
                ans[0] = mid;
            }

            // Look furhter left
            u = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    // If we didnt find the first occurence no need to check last occurence
    if (ans[0] != -1)
    {
        // l = ans[0] , since last occurence >= first occurence
        l = ans[0], u = nums.size() - 1, mid;
        while (l <= u)
        {
            mid = l + (u - l) / 2;
            if (nums[mid] <= target)
            {
                if (nums[mid] == target)
                {
                    ans[1] = mid;
                }

                // Look further right
                l = mid + 1;
            }
            else
            {
                u = mid - 1;
            }
        }
    }
    return ans;
}