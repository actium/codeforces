int main()
{
    int n = (int)Stdio.stdin->gets();
    string input = Stdio.stdin->gets();

    array(string) s = input/",";

    int i = 0, x = 1;
    while (i < n) {
        int v = abs((int)s[i]);
        if (v > x && v % x != 0 || v < x && x % v != 0) {
            write("NOT FRIENDS");
            return 0;
        }
        x = v;
        i = i + 1;
    }

    write("FRIENDS");

    return 0;
}
