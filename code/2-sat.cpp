// 2-SAT solver
// linear time

struct SatInstance {
    int nvars, n, nc;
    int maxv;
    vi root, comp, size, vis;
    stack<int> s;
    vvi adj;

    SatInstance(int nv) : nvars(nv) {
        n=0;
        maxv = 2*nv+2; //max Verticies, maybe set to 1000 or similar
        adj = vvi(maxv);
    }

    inline int T(int x){return 2*x;}
    inline int F(int x){return 2*x+1;}

    void AddClause(int x, bool bx, int y, bool by ) { // (x = bx or y = by) and ....
        int hipx, hipy , tx, ty;
        if (bx)
            hipx = F(x) , ty = T(x);
        else
            hipx = T(x) , ty = F(x);

        if (by)
            hipy = F(y) , tx = T(y);
        else
            hipy = T(y) , tx = F(y);
        adj[hipx].push_back(tx);
        adj[hipy].push_back(ty);
        n = max(n, max(hipx, hipy));
    }

    void SCC() {
        root = comp = size = vis = vi(maxv);
        nc = 0;
        for (int i = 1; i <= n; ++i)
            if (!vis[i])
                tarjan(i, 0);
    }
    void tarjan(int v, int d) {
        root[v] = d; vis[v]=1; s.push(v);
        for (size_t i = 0; i < adj[v].size(); ++i) {
            if (!vis[adj[v][i]])
                tarjan(adj[v][i], d+1);
            if (comp[adj[v][i]] == 0)
                root[v] = min(root[v], root[adj[v][i]]);
        }
        if (root[v] == d) {
            comp[v] = ++nc;
            for (size[nc] = 1; s.top() != v; s.pop(), size[nc]++)
                comp[s.top()] = nc;
            s.pop();
        }
    }
    bool IsSatisfiable() {
        SCC();
        bool ok = true;
        for (int i = 1; ok && i <= nvars; ++i)
            ok = comp[T(i)] != comp[F(i)];
        return ok;
    }
};
