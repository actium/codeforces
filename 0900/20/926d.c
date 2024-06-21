#include <stdio.h>

void answer(char g[6][9])
{
    for (int i = 0; i < 6; ++i)
        printf("%s\n", g[i]);
}

void solve(char g[6][9])
{
    int r, c, v = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (g[i][j] != '.')
                continue;

            int u = (7 - i) / 2 + !!(j > 2 && j < 5);
            if (u > v) {
                v = u;
                r = i;
                c = j;
            }
        }
    }

    g[r][c] = 'P';
    answer(g);
}

int main()
{
    char g[6][9];
    for (int i = 0; i < 6; ++i)
        scanf("%s", g[i]);

    solve(g);

    return 0;
}
