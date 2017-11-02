typedef pair<ll, ll> llll;

enum line_type{
    normal,
    minus_infinity,
    infinity,
    value
};

ll gcd(ll a, ll b){
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct fraction{
    ll a, b;
    fraction(ll _a, ll _b = 1) : a(_a), b(_b){
        if (a == 0 && b == 0) return;
        if (b < 0) a = -a, b = -b;
        ll c = gcd(abs(a), b);
        a /= c, b /= c;
    }

    operator llll() const{
        return llll(a, b);
    }
};

inline bool operator<(const fraction& f1, const fraction& f2){
    if (llll(f1) == llll(f2)) return false;
    if (llll(f1) == llll(-1, 0) || llll(f2) == llll(1, 0)) return true;
    if (llll(f1) == llll(1, 0) || llll(f2) == llll(-1, 0)) return false;
    return ld(f1.a) * ld(f2.b) < ld(f2.a) * ld(f1.b);
}

struct line{
    ll a, b;
    line_type t = normal;
    set<line>::iterator* it = new set<line>::iterator;

    line(ll _a, ll _b) : a(_a), b(_b){}
    line(ll _x) : a(0), b(_x), t(value){}
    line(const line& other) : a(other.a), b(other.b), t(other.t){
        *it = *other.it;
    }
    line& operator=(const line& other){
        a = other.a;
        b = other.b;
        t = other.t;
        *it = *other.it;
        return *this;
    }

    ll operator()(ll x) const{
        return a * x + b;
    }

    static line left_edge(){
        line ret(0);
        ret.t = minus_infinity;
        return ret;
    }

    static line right_edge(){
        line ret(0);
        ret.t = infinity;
        return ret;
    }

    ~line(){
        delete it;
    }
};

inline fraction intersection(const line& l1, const line& l2){
    if (l1.t == infinity || l2.t == infinity) return fraction(1, 0);
    if (l1.t == minus_infinity || l2.t == minus_infinity) return fraction(-1, 0);
    return fraction(l1.b - l2.b, l2.a - l1.a);
}

inline bool operator<(const line& l1, const line& l2){
    if (l1.t == normal && l2.t == normal) return llll(-l1.a, l1.b) < llll(-l2.a, l2.b);
    if (l1.t == minus_infinity || l2.t == infinity) return true;
    if (l1.t == infinity || l2.t == minus_infinity) return false;
    if (l1.t == value) return fraction(l1.b) < intersection(*prev(*l2.it), l2);
    return !(fraction(l2.b) < intersection(l1, *next(*l1.it)));
}

struct cht{
    set<line> s = {line::left_edge(), line::right_edge()};

    cht(){
        *(s.begin()->it) = s.begin();
        *(next(s.begin())->it) = next(s.begin());
    }

    void insert_line(const line& l){
        set<line>::iterator it2 = s.lower_bound(l), it1 = prev(it2);
        if (it1 != s.begin() && (it1->a == l.a || !(intersection(*it1, l) < intersection(*it1, *it2)))) return;
        if (it2 != prev(s.end()) && l.a == it2->a) ++it2;
        while (it1 != s.begin() && !(intersection(*prev(it1), *it1) < intersection(*it1, l))) --it1;
        while (it2 != prev(s.end()) && !(intersection(*it2, l) < intersection(*it2, *next(it2)))) ++it2;
        while (next(it1) != it2) s.erase(next(it1));
        set<line>::iterator it = s.insert(it1, l);
        *(it->it) = it;
    }

    ll operator()(ll x){
        return (*prev(s.upper_bound(line(x))))(x);
    }
};
