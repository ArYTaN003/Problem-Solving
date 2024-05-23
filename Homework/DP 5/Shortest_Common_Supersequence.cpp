class Solution {
public:
    /*
    Recursive/Memoization

    string maxS(string s1,string s2){
        if(s1.length()>s2.length()) return s1;
        return s2;
    }
    string getLCS(string& s1,string&s2,int i,int j,int& n,int &m,vector<vector<string>>& dp){
        if(i==n || j==m) return "";
        if(dp[i][j]!="") return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j] = s1[i]+getLCS(s1,s2,i+1,j+1,n,m,dp);
        }else{
            return dp[i][j] = maxS(getLCS(s1,s2,i+1,j,n,m,dp),getLCS(s1,s2,i,j+1,n,m,dp));
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(),m=str2.length();
        vector<vector<string>> dp(n,vector<string>(m,""));
        string lcs = getLCS(str1,str2,0,0,n,m,dp);
        int t1 = 0,t2 = 0;
        string super_seq = "";
        for(int i=0;i<lcs.length();i++){
            while(t1<n && str1[t1]!=lcs[i]){
                super_seq+=str1[t1];
                t1++;
            }
            t1++;
            while(t2<m && str2[t2]!=lcs[i]){
                super_seq+=str2[t2];
                t2++;
            }
            t2++;
            super_seq+=lcs[i];
        }
        while(t1<n){
            super_seq+=str1[t1];
            t1++;
        }   
        while(t2<m){
            super_seq+=str2[t2];
            t2++;
        }
        return super_seq;
    }
    */
    string getLCS(string &text1,string& text2,int &n,int &m){
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = text1[0]==text2[0];
        for(int i=1;i<m;i++){
            dp[0][i] = max(dp[0][i-1],(int)(text1[0]==text2[i]));
        }
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],(int)(text1[i]==text2[0]));
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(text1[i]==text2[j]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string lcs = "";
        int i=n-1,j=m-1;
        while(i-1>=0 && j-1>=0){
            if(text1[i]==text2[j]){
                lcs = text1[i]+lcs;
                i--;
                j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
        while(i==0 && j>=0){
            if(text1[i]==text2[j]){
                lcs = text1[i]+lcs;
                i--;
            }
            j--;
        }
        while(j==0 && i>=0){
            if(text1[i]==text2[j]){
                lcs = text1[i]+lcs;
                j--;
            }
            i--;
        }
        // cout << lcs << endl;
        return lcs;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(),m=str2.length();
        string lcs = getLCS(str1,str2,n,m);
        int t1 = 0,t2 = 0;
        string super_seq = "";
        for(int i=0;i<lcs.length();i++){
            while(t1<n && str1[t1]!=lcs[i]){
                super_seq+=str1[t1];
                t1++;
            }
            t1++;
            while(t2<m && str2[t2]!=lcs[i]){
                super_seq+=str2[t2];
                t2++;
            }
            t2++;
            super_seq+=lcs[i];
        }
        while(t1<n){
            super_seq+=str1[t1];
            t1++;
        }   
        while(t2<m){
            super_seq+=str2[t2];
            t2++;
        }
        return super_seq;
    }
};