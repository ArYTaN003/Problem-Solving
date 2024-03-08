int findKRotation(int arr[], int n)
{
    int l = 0, u = n - 1, mid;
    // Find min element , the deviation of min element from 0th index will be the number of rotations
    // We can use binary Search to find the min element
    while (l < u)
    {
        mid = l + (u - l) / 2;
        if (arr[mid] < arr[u])
        {
            u = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}