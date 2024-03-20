bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // We use one binary search to find the row in which our target could be present
        // Then we use another binary search to find whether element is present in that row or not.
        int l = 0,h = matrix.size()-1;
        int mid;
        while(l<=h){
            mid = l + (h-l)/2;
            if(target<matrix[mid][0]){
                // Since first element of the row is greater , target will be in a row above it
                h=mid-1;
            } 
            else if(target>matrix[mid][matrix[0].size()-1]){
                // Since last element of the row is smaller than target , target will be in a row below it
                l=mid+1;
            }else{
                int s=0,e=matrix[0].size()-1;
                int m;
                while(s<=e){
                    m = s+(e-s)/2;
                    if(matrix[mid][m]==target){
                        return true;
                    }else if(matrix[mid][m]>target){
                        e=m-1;
                    }else{
                        s=m+1;
                    }
                }
                break;
            }
        }
        return false;
    }