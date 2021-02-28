int itoa(int i, char a[]) {
    int len = 0;
    do
        a[len++] = '0' + i % 10;
    while (i /= 10);
    a[len] = '\0';
    return i;
}