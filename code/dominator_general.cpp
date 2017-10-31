namespace dominator{
    int T, n;
    vvi g, rg, bucket;
    vi sdom, par, dom, dsu, label, arr, rev;

    int find(int u, int x = 0){
        if (u == dsu[u]) return x ? -1 : u;
        int v = find(dsu[u], x + 1);
        if (v < 0) return u;
        if (sdom[label[dsu[u]]] < sdom[label[u]]) label[u] = label[dsu[u]];
        dsu[u] = v;
        return x ? v : label[u];
    }

    void unite(int u, int v){
        dsu[v] = u;
    }

    void dfs(int u){
        T++; arr[u] = T; rev[T] = u;
        label[T] = T; sdom[T] = T; dsu[T] = T;
        loop(i, 0, g[u].size()){
            int w = g[u][i];
            if (!arr[w]) dfs(w), par[arr[w]] = arr[u];
            rg[arr[w]].PB(arr[u]);
        }
    }

    static vi get(const graph& G, int root){
        T = 0, n = G.size();
        int k = n + 1;
        g.assign(k, {}), rg.assign(k, {}), bucket.assign(k, {});
        sdom.assign(k, 0), par.assign(k, 0), dom.assign(k, 0), dsu.assign(k, 0), label.assign(k, 0), arr.assign(k, 0), rev.assign(k, 0);

        loop(i, 0, G.size()) for (auto& x : G[i]) g[i + 1].PB(x + 1);
        ++root;
        vector<int> res(n, -1);
        dfs(root); n = T;
        loop_rev(i, n, 1){
            loop(j, 0, rg[i].size()) sdom[i] = min(sdom[i], sdom[find(rg[i][j])]);
            if (i > 1) bucket[sdom[i]].PB(i);
            loop(j, 0, bucket[i].size()){
                int w = bucket[i][j],v = find(w);
                if (sdom[v] == sdom[w]) dom[w] = sdom[w];
                else dom[w] = v;
            }
            if (i > 1) unite(par[i], i);
        }
        loop(i, 2, n + 1){
            if (dom[i] != sdom[i]) dom[i] = dom[dom[i]];
            res[rev[i] - 1] = rev[dom[i]] - 1;
        }
        return res;
    }
}
