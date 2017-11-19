typedef vector<ll> vec;
typedef vector<vec> mat;

ll mod = 1e9 + 7;

inline vec operator*(const mat& A, const vec& X){
    vec res(A.size(), 0);
    loop(i, 0, A.size()) loop(j, 0, A[i].size()) res[i] = (res[i] + (A[i][j] * X[j]) % mod) % mod;
    return res;
}

inline bool operator!=(const vec& X, const vec& Y){
    loop(i, 0, X.size()) if (X[i] != Y[i]) return true;
    return false;
}

bool solve(int n){
    mat A(n, vec(n)), B = A;
    for (auto& x : A) for (auto& y : x) cin >> y;
    for (auto& x : B) for (auto& y : x) cin >> y;
    int k = 10;
    loop(i, 0, k){
        vec X(n);
        for (auto& x : X) x = rand() % mod;
        if (A * (A * X) != B * X) return false;
    }
    return true;
}
//add srand(4728);

