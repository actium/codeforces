int main()
{
    int n = (int)Stdio.stdin->gets();
    array(string) s = Stdio.stdin->gets() / " ";

    int k = (int)Stdio.stdin->gets();
    array(string) q = Stdio.stdin->gets() / " ";

    array(int) f = allocate(n);
    for (int i = 0; i < k; i = i + 1) {
        int x = (int)q[i] - 1;
        f[x] = f[x] ^ 1;
    }

    for (int i = 1; i <= n; i = i + 1) {
        if (f[i-1] == 0)
            continue;

        for (int j = i - 1; j < n; j = j + i)
            s[j] = (s[j] == "on" ? "off" : "on");
    }

    foreach (s, string x)
        write(x + " ");

    return 0;
}
