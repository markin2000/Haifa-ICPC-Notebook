struct fraction{
    ll a, b;
    fraction(ll _a, ll _b = 1) : a(_a), b(_b){}
};

bool operator<(const fraction& f1, const fraction& f2){
    return f1.a * f2.b < f2.a * f1.b;
}

struct line{
    ll a, b;

    line(ll _a, ll _b) : a(_a), b(_b){}

    ll operator()(ll x) const{
        return a * x + b;
    }
};

inline fraction intersection(const line& l1, const line& l2){
    return fraction(l1.b - l2.b, l2.a - l1.a);
}

struct cht{
    int pos = 0;
    vector<line> arr = {};

    cht(){}

    void insert_line_at_end(const line& l){
        if (arr.size() != 0 && !(llll(l.a, l.b) < llll(arr.back().a, arr.back().b))) return;
        if (arr.size() != 0 && l.a == arr.back().a) arr.pop_back();
        while (arr.size() >= 2 && !(intersection(arr[arr.size() - 2], arr.back()) < intersection(arr.back(), l))) arr.pop_back();
        arr.push_back(l);
    }

    ll operator()(ll x){
        pos = min(pos, int(arr.size()) - 1);
        while (pos != 0 && arr[pos - 1](x) < arr[pos](x)) --pos;
        while (pos != int(arr.size()) - 1 && arr[pos](x) >= arr[pos + 1](x)) ++pos;
        return arr[pos](x);
    }
};
