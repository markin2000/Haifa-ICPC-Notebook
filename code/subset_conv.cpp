const unsigned int mod = 1'000'000''007;

void trans(vi& p){
    int n = p.size();
    for(int c = 1; c < n; c+=c)
    loop(i, 0, n)
    if(i & c)
        p[i] += p[i-c];
}

void invtrans(vi& p){
    int n = p.size();
    for(int c = n/2; c; c /=2)
    for(int i = n-1; i>= 0; i--)
    if(i & c)
        p[i] -= p[i-c];
}

vi mul(vi p1, vi p2){
    int n = p1.size();

    //loop(j, 0, n) cerr << p1[j]; cerr << endl;
    //loop(j, 0, n) cerr << p2[j]; cerr << endl;
    //cerr << endl;
    trans(p1);
    //loop(j, 0, n) cerr << p1[j]; cerr << endl;
    trans(p2);
    //loop(j, 0, n) cerr << p2[j]; cerr << endl;

    loop(i, 0, n) p1[i] *= p2[i];

    invtrans(p1);

    //loop(j, 0, n) cerr << p1[j]; cerr << endl;
    //cerr << endl;
    return p1;
}


int32_t main(){
    ios::sync_with_stdio(false);

    int n, m, k; cin >> n >> m >> k;
    vvi A(m, vi(1 << n));
    loop(i, 0, m)
    loop(j, 0, (1 << n)){
        char c; cin >> c;
        A[i][j] = (c == '1');
    }
    loop(i, 0 , k){
        int a,b ; cin >> a >> b;
        vi ans = mul(A[a], A[b]);
        loop(j, 0 , (1 << n))
            cout << (ans[j] ? 1 : 0);
        cout << endl;
    }


    return 0;
}

/*

3 5 3
11111010
11000000
11001000
11101000
11101000
0 1
1 2
3 4


*/
