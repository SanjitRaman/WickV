int g()
{
            int i = 12;
            int y = 3;
            int x = (y+i)*y;
            i++;
            ++i;
            i++;
            --y;
            --y;
            i--;
            x--;
            x++;
            --x;
            return (x + i)/y;
}
