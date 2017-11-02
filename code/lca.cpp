//maybe remove

int LOGN;
vector<vector<int> > LCA;
vector<int> depth;
vector<vector<int> > tree;
void dfs(int u,int dep){
    depth[u] = dep;
    for(int v : tree[u])
        dfs(v,dep+1);
}

void init(int N, int fathers[]){
    tree.assign(N,vector<int>());
    int root = -1;
    for(int i = 0;i<N;i++)
        if(fathers[i] == -1)
            root = i,fathers[i] = i;
        else
            tree[fathers[i]].push_back(i);
    depth.assign(N,0);
    dfs(root,0);
    LOGN = 3;
    for(int n = N;n/=2;LOGN++);
    LCA.assign(LOGN,vector<int>(N));
    for(int i = 0;i<N;i++)
        LCA[0][i] = fathers[i];
    for(int d = 1;d<LOGN;d++)
    for(int i = 0;i<N;i++)
        LCA[d][i] = LCA[d-1][LCA[d-1][i]];
}

int query(int u,int v){
    if(depth[u] < depth[v])
        swap(u,v);
    for(int d = LOGN-1;d>=0;d--)
    if(depth[LCA[d][u]] >= depth[v])
        u = LCA[d][u];
    if(u == v)
        return u;
    for(int d = LOGN-1;d>=0;d--)
    if(LCA[d][u] != LCA[d][v])
        u = LCA[d][u],v = LCA[d][v];
    return LCA[0][u];
}

int main()
{
    int t; cin >> t;
    for(int r = 0;r<t;r++){
        int n; cin >> n;
        int *fathers = new int[n];
        for(int i = 0;i<n;i++) fathers[i] = -1;
        for(int i = 0;i<n;i++){
            int m; cin >> m;
            for(int j = 0;j<m;j++){
                int x; cin >> x;
                fathers[x-1] = i;
            }
        }
        init(n,fathers);
        cout << "Case " << r+1 << ":\n";
        int q; cin >> q;
        for(int a = 0;a<q;a++){
            int u,v; cin >> u >> v;
            cout << query(u-1,v-1)+1 << endl;
        }
    }
    return 0;
}
