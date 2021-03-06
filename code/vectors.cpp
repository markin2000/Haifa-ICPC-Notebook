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

bool inTriangle(ii a, ii b, ii c, ii p){
    int sign1 = sign(cross(a-p,b-a));
    int sign2 = sign(cross(b-p,c-b));
    int sign3 = sign(cross(c-p,a-c));
    if(max(sign1,max(sign2,sign3)) == 1 && min(sign1,min(sign2,sign3)) == -1)
        return false;
    return true;
}

ll area(vector<ii> shape){ // counter-clockwise
    ll sum = 0;
    while (shape.size() > 2){
        sum += cross(shape[shape.size() - 2] - shape[0], shape[shape.size() - 1] - shape[0]);
        shape.pop_back();
    }
    return sum;
}
