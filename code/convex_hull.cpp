inline int lowest_point(vector<ii>& P){
	return min_element(P.begin(), P.end(), [](ii a, ii b){return ii(a.second, a.first) < ii(b.second, b.first);}) - P.begin();
}

vector<ii> convex_hull(vector<ii> S){
    int first = lowest_point(S);
    ii origin = S[first];
    S.erase(S.begin() + first);
    //sort by angle
    sort(S.begin(), S.end(), [&origin](ii p1, ii p2){return ii(-cross(p1 - origin, p2 - origin), norm(p1 - origin)) < ii(0, norm(p2 - origin));});

    vector<ii> hull = {origin};
    for (auto& p : S){
        while(hull.size() >= 2 && cross(hull[hull.size() - 1] - hull[hull.size() - 2], p - hull[hull.size() - 1]) <= 0) hull.pop_back();
        hull.push_back(p);
    }
    return hull;
}
