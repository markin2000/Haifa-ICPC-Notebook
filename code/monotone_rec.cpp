void rec(int n1, int n2, int m1, int m2, DSU dsu){
    if(n2 < n1 || m2 < m1) return;
    int mid = (n1 + n2) / 2;
    DSU dsu2 = dsu;
    for(int i = mid; i <= min(n2,m1-1); i++){
        dsu.uni(E[i].u, E[i].v);
    }
    DSU dsu1 = dsu;
    int k = max(m1-1, mid-1);
    while(k < m2 && !dsu.single()){
        if (k > n2) dsu2.uni(E[k].u, E[k].v);
        ++k;
        dsu.uni(E[k].u, E[k].v);
    }

    if(dsu.single()){
        ans[mid] = k;
        rec(n1, mid-1, m1, k, dsu1);
        rec(mid+1, n2, k, m2, dsu2);
    }
    else{
        rec(n1, mid-1, m1, m2, dsu1);
    }
}
