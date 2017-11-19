
const int inf = 1e9;
int main()
{
    int n,m; cin >> n >> m;
    vector<vector<int> > D(n,vector<int>(n,inf));
    for(int i=0;i<m;i++){
        int a,b,d; cin >>a >> b >> d;
        D[a-1][b-1] = D[b-1][a-1] = d;
    }
    for(int i = 0;i<n;D[i][i++] = 0);
    for(int k = 0;k<n;k++){
        for(int j = 0;j<n;j++){
            for(int i = 0;i<n;i++){
                D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
            }
        }
    }

    return 0;
}
