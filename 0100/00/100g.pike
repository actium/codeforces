int main()
{
    int n = (int)Stdio.stdin->gets();

    mapping(string:int) r = ([]);
    for (int i = 0; i < n; i = i + 1) {
        array(string) x = Stdio.stdin->gets() / " ";
        r[x[0]] = (int)x[1];
    }

    string a = "";

    int m = (int)Stdio.stdin->gets();
    for (int i = 0; i < m; i = i + 1) {
        string x = Stdio.stdin->gets();

        if (a == "" || zero_type(r[x]) && !zero_type(r[a])) {
            a = x;
            continue;
        }
        if (zero_type(r[x]) && zero_type(r[a])) {
            a = max(a, x);
            continue;
        }
        if (!zero_type(r[a]) && (r[x] < r[a] || r[x] == r[a] && x > a))
            a = x;
    }

    write(a);

    return 0;
}
