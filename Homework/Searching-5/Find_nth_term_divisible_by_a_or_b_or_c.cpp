int gcd(int a, int b)
{
    if (a == 0) return b;
 
    return gcd(b % a, a);
}
int lcm(int a, int b)
{
    return (a * b)/gcd(a, b);
}
int count(int a, int b, int c, int num)
{
    int adiv = num/a;
    int bdiv = num/b;
    int cdiv = num/c;
    int a_and_bdiv = num/lcm(a,b); //  Common elements divisible by a,b
    int a_and_cdiv = num/lcm(a,c);//  Common elements divisible by a,c
    int b_and_cdiv = num/lcm(b,c);//  Common elements divisible by b,c
    int a_b_cdiv = num/lcm(a,lcm(b,c));//  Common elements divisible by a,b,c
    int count = adiv+bdiv+cdiv-a_and_bdiv-a_and_cdiv-b_and_cdiv+a_b_cdiv;  
    return count;
}
int findNthTerm(int a, int b, int c, int n)
{
    // Search Space -> [1,max(a,b,c)*n]
    // Condition -> If the number of elements divisible by a,b,c is n till mid , then mid is the answer,
    // If number of elements divisible by a,b,c is less than n till mid , means our answer lies on the right side
  // If number of elements divisible by a,b,c is greater than n till mid, means out answer lies on the left side 
    // number of elements divisible by a number num till a number m = m/num
    // Ex-> number of elements divisible by 3 till 10 = 10/3 = 2 ,i.e. 3,9 
    int l = 1, h = max(a,max(b,c))*n, mid;
 	int ans;
    while (l <= h) {
        mid = l + (h - l) / 2;
      int temp = count(a,b,c,mid);
        if(temp==n){
          	break;
        }else if(temp<n){
            l = mid+1;
        }
        else{
        	h = mid-1;
        }
    }
    return mid;
}