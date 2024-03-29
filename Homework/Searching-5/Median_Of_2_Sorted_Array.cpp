double kthelement(vector<int>& a, vector<int>& b, int n, int m, int k) {
    if (n > m) return kthelement(b, a, m, n, k);
    
    int l = max(0, k - m);
    int h = min(k, n);

    while (l <= h) {
        int amid = l + (h - l) / 2;
        int bmid = k - amid;

        int aleft = (amid == 0) ? INT_MIN : a[amid - 1];
        int bleft = (bmid == 0) ? INT_MIN : b[bmid - 1];
        int aright = (amid == n) ? INT_MAX : a[amid];
        int bright = (bmid == m) ? INT_MAX : b[bmid];

        if (aleft <= bright && bleft <= aright) {
            return max(aleft, bleft);
        } else if (aleft > bright) {
            h = amid - 1;
        } else {
            l = amid + 1;
        }
    }
    return -1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    int mid = total / 2;
    
    if (total % 2 == 0) {
        // We are finding mid,mid+1 th element as the kthelement function returns the element at k-1 index.
        double ele1 = kthelement(nums1, nums2, nums1.size(), nums2.size(), mid);
        double ele2 = kthelement(nums1, nums2, nums1.size(), nums2.size(), mid+1);
        return (ele1 + ele2) / 2.0;
    } else {
        return kthelement(nums1, nums2, nums1.size(), nums2.size(), mid+1);
    }
}