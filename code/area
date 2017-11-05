ll cross(ii x, ii y){
    return x.first * y.second - x.second * y.first;
}

ii operator-(ii x, ii y){
    return ii(x.first - y.first, x.second - y.second);
}

ll area(vector<ii> shape){ // counter-clockwise
    ll sum = 0;
    while (shape.size() > 2){
        sum += cross(shape[shape.size() - 2] - shape[0], shape[shape.size() - 1] - shape[0]);
        shape.pop_back();
    }
    return sum;
}
