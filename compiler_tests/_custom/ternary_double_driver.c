int f(int x);

int main() { return !(f(1) == 1 && f(-1) == 0); }