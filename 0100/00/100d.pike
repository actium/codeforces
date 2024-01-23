int main()
{
    int n = (int)Stdio.stdin->gets();
    string s = Stdio.stdin->gets();
    string t = Stdio.stdin->gets();

    int u = strlen(s), v = strlen(t);

    int i = 0;
    while (i < u && i < v && s[i] == t[i])
        i = i + 1;

    if (u - i + v - i > n)
        write("NO");
    else
        write("YES");

    return 0;
}
