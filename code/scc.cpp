int n;
vector<int> visited;
vector<vector<int> > G,Gt;
stack<int> S;
vector<vector<int> > SC;
void dfs(int u){
    visited[u] = 1;
    for(int v: G[u]){
        if(!visited[v])
            dfs(v);
    }
    S.push(u);
}

void dfs2(int u){
    visited[u] = 2;
    for(int v : Gt[u]){
        if(visited[v] != 2){
            dfs2(v);
        }
    }
    SC.back().push_back(u);
}

void SCC(){
    for(int i = 0;i<n;i++)
        if(!visited[i])
            dfs(i);
    while(!S.empty()){
        int i = S.top();
        S.pop();
        if(visited[i] != 2){
            SC.push_back({});
            dfs2(i);
        }
    }
}
