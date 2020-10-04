int main()
{
    string input = Stdio.stdin->gets();

    int n, k, m;
    sscanf(input, "%d %d %d", n, k, m);

    int c = (n + m - 1) / m;
    if (k < c * c)
        write("NO");
    else
        write("YES");

    return 0;
}

