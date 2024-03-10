int NthRoot(int n, int m)
{
    int i;
    for (i = 1; pow(i, n) < m; i++);
    return pow(i, n) == m ? i : -1;
}