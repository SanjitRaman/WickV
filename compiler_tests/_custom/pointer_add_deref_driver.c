int f();

int main()
{
    int x = 5;
    return !(f(&x)==6);
}