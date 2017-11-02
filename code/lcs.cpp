vector<char> LCS(string a, string b){
    int n = a.size(), m = b.size();
    vector<vector<int> > dp(n,vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(a[i] == b[j])
                dp[i][j] = (j && i)? dp[i-1][j-1]+1 : 1;
            else
                dp[i][j] = max(j? dp[i][j-1] : 0,i? dp[i-1][j] : 0);
        }
    }
    stack<char> ans;
    for(int i = n-1,j = m-1;i>=0 && j>=0;){
        if(a[i] == b[j]){
            ans.push(a[i]);
            i--;j--;
        }
        else{
            if((i? dp[i-1][j] : 0) < (j? dp[i][j-1] : 0))
                j--;
            else
                i--;
        }
    }
    vector<char> res;
    while(!ans.empty())
        res.push_back(ans.top()),ans.pop();
    return res;
}
