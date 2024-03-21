int f();

int main() { return !(f(1.0) == 1 && f(-1.0) == 0); }