int f(int x){
    int *y = &x;
    *y = 6;
    return *y;
}