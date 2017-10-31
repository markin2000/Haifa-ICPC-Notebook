typedef double T;
typedef pair<T, T> ii;
typedef pair<ii, T> i3;
typedef pair<ii, ii> i4;

inline double cross(ii a, ii b){
    return a.first * b.y - a.y * b.first;
}

inline ii operator+(ii a, ii b){
    return ii(a.first + b.first, a.y + b.y);
}

inline ii operator-(ii a, ii b){
    return ii(a.first - b.first, a.y - b.y);
}

inline double operator*(ii a, ii b){
    return a.first * b.first + a.y * b.y;
}

inline ii operator/(ii a, double b){
    return ii(a.first / b, a.y / b);
}

inline T norm(ii x){
    return x * x;
}

inline int sig(double x){
    return x > 0 ? 1 : x == 0 ? 0 : -1;
}

inline double distance(ii a, ii b){
    return sqrt(norm(b - a));
}
