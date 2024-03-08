bool search(vector<int> &arr, int target)
{
    int l = 0, u = arr.size() - 1, mid;
    while (l <= u)
    {
        mid = l + (u - l) / 2;
        if (arr[mid] == target)
            return true;
        if (arr[mid] == arr[l] && arr[mid] == arr[u])
        {
            l++;
            u--;
        }
        else if (arr[mid] <= arr[u])
        {
            // mid in right part
            if (arr[mid] < target && arr[u] >= target)
            {
                // target in left part
                l = mid + 1;
            }
            else
            {
                // target in right part
                u = mid - 1;
            }
        }
        else
        {
            // mid in left part
            if (arr[mid] > target && arr[l] <= target)
            {
                // target in left part
                u = mid - 1;
            }
            else
            {
                // target in right part
                l = mid + 1;
            }
        }
    }
    return false;
}