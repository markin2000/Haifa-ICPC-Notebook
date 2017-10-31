vector<int> dijkstra(const graph_w& G, int s){
    int n = G.size();
    vector<int> dis(n, inf);
    set<ii> S;
    dis[s] = 0;
    S.insert({0, s});
    while(!S.empty()){
        int u = S.begin()->second;
        S.erase(S.begin());

        for(auto& e : G[u]){
            int v = e.first, w = e.second;
            if(dis[v] > dis[u] + w){
                S.erase({dis[v], v});
                dis[v] = dis[u] + w;
                S.insert({dis[v], v});
            }
        }
    }
    return dis;
}
