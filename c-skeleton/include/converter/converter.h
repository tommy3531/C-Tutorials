void toBinary(int n);
void convertBase(int n, int base);

void toBinary(int n)
{
    if(n == 0)
    {
        return;
    }
    toBinary(n/2);
    printf("%d", n % 2);
}

void convertBase(int n, int base)
{
    int remainder;
    if(n == 0)
    {
        return;
    }
    convertBase(n/base, base);

    remainder = n % base;

    if(remainder < 10)
    {
        printf("%d", remainder);
    }
    else
    {
        printf("%c\n", remainder-10+ 'A');
    }
}