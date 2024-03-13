bool canPaint(vector<int>& boards,int k,int maxdistance){
    int sum = 0,i,numWorkers=1;
    for(i=0;i<boards.size();i++){
        sum+=boards[i];
        if(sum>maxdistance){
            // cout << sum << " ";
            numWorkers++;
            sum = boards[i];
            if(sum>maxdistance){
                numWorkers++;
                sum = 0;
            }
        }
    }
    // cout << k << endl;
    return k>=numWorkers && i==boards.size();
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    // Search Space -> [max(boards),sum(boards)]
    // Condition -> if it is possible for k painters to paint all boards with atmost mid distance, then
    // mid is a potential candidate and we look for a lower value , otherwise we look for a higher value.
    int sum = 0;
    for(int i=0;i<boards.size();i++){
        sum+=boards[i];
    }
    int l = *max_element(boards.begin(),boards.end());
    int h=sum,mid,ans;
    while(l<=h){
        mid = l+(h-l)/2;
        // cout << l << " " << mid << " " << h << endl;
        if(canPaint(boards,k,mid)){
            ans = mid;
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}