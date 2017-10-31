
bool inside_circle(i3 circle, ii p){
    return distance(circle.first, p) <= circle.second;
}

i3 circle_from_2_points(ii a, ii b){
    return {(a+b)/2, distance(a, b)/2};
}

i3 circle_from_3_points(ii a, ii b, ii c){
    double d = 2.0*(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
    double xc = ((a.x * a.x + a.y * a.y) * (b.y - c.y) + (b.first * b.first + b.y * b.y) * (c.y - a.y) + (c.first * c.first + c.y * c.y) * (a.y - b.y) ) / d;
    double yc = ((a.first * a.first + a.y * a.y) * (c.first - b.first) + (b.first * b.first + b.y * b.y) * (a.first - c.first) + (c.first * c.first + c.y * c.y) * (b.first - a.first) ) / d;
    cerr << xc << " " << yc << endl;
    ii center = {xc, yc};
    return {center, distance(center, a)};
}

i3 minimal_bounding_circle_3(vector<ii>& P, ii a, ii b){
    i3 circle = circle_from_2_points(a, b);
    for(ii p : P){
        if(!inside_circle(circle, p)){
            circle = circle_from_3_points(a, b, p);
        }
    }
    return circle;
}

i3 minimal_bounding_circle_2(vector<ii>& P, ii a){
    i3 circle = circle_from_2_points(a, P[0]);
    vector<ii> P2 = {P[0]};
    for(int i = 1; i < (int)P.size(); ++i){
        ii p = P[i];
        if(!inside_circle(circle, p)){
            circle = minimal_bounding_circle_3(P2, a, p);
        }
        P2.push_back(P[i]);
    }
    return circle;
}

i3 minimal_bounding_circle(vector<ii>& P){
    if(P.size() < 2) return {{0,0}, -1}; // null!
    random_shuffle(P.begin(), P.end());

    i3 circle = circle_from_2_points(P[0], P[1]);
    vector<ii> P2 = {P[0], P[1]};
    for(int i = 2; i < (int)P.size(); ++i){
        ii p = P[i];
        if(!inside_circle(circle, p)){
            circle = minimal_bounding_circle_2(P2, p);
        }
        P2.push_back(P[i]);
    }
    return circle;
}
