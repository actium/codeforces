#include <stdio.h>

void answer(const char* x)
{
    printf("%s\n", x);
}

void solve(int n, const char* s)
{
    char t[100001];
    {
        int i = 0, k = 0;
        while (i < n) {
            if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'y') {
                for (t[k++] = s[i++]; s[i] == t[k-1]; ++i);
                continue;
            }
            if (s[i] == 'e' || s[i] == 'o') {
                int x = i;
                while (s[i] == s[x])
                    ++i;

                t[k++] = s[x];
                if (i - x == 2)
                    t[k++] = s[x];
            } else {
                t[k++] = s[i++];
            }
        }
        t[k] = '\0';
    }

    answer(t);
}

int main()
{
    int n;
    scanf("%d", &n);

    char s[100001];
    scanf("%s", s);

    solve(n, s);

    return 0;
}
