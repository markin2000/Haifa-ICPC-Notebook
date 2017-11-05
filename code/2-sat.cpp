void scc_dfs(const graph& G, int v, vector<int>& visit, vector<int>& stack){
    if (visit[v]) return;

    visit[v] = true;
    for (auto& x : G[v]) scc_dfs(G, x, visit, stack);
    stack.push_back(v);
}

void scc_dfs(const graph& G, int v, int s, vector<int>& visit, vector<int>& res){
    if (visit[v]) return;

    visit[v] = true;
    res[v] = s;
    for (auto& x : G[v]) scc_dfs(G, x, s, visit, res);
}

inline vector<int> scc_t_sort(const graph& G){
    graph G_rev(G.size());
    loop(i, 0, G.size()) for (auto& j : G[i]) G_rev[j].push_back(i);
    vector<int> visit(G.size(), false), stack;
    loop(i, 0, G.size()) scc_dfs(G, i, visit, stack);
    visit.assign(G.size(), false);
    vector<int> ret(G.size());
    int counter = 0;
    while (stack.size()) scc_dfs(G_rev, stack.back(), counter++, visit, ret), stack.pop_back();
    return ret;
}

inline void add_or(graph& G, int a, int b, const vector<int>& not_v){
    G[not_v[a]].push_back(b);
    G[not_v[b]].push_back(a);
}

vector<int> sat_2(const vector<ii>& or_c, const vector<int>& not_v){
    graph G(not_v.size());
    for (auto& x : or_c) add_or(G, x.first, x.second, not_v);
    vector<int> arr = scc_t_sort(G);
    loop(i, 0, arr.size()) if (arr[i] == arr[not_v[i]]) return {};
    vector<int> val(G.size());
    loop(i, 0, arr.size()) if (arr[i] > arr[not_v[i]]) val[i] = true, val[not_v[i]] = false;
    return val;
}
