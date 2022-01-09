#include <iostream>

void answer(unsigned x, unsigned y)
{
    printf("%02u:%02u\n", x, y);
}

void solve(unsigned h, unsigned m, unsigned sh, unsigned sm)
{
    const auto test = [eh = h, em = m](unsigned h, unsigned m) {
        constexpr int x[10] = { 0, 1, 5, -1, -1, 2, -1, -1, 8, -1 };

        if (x[h/10] == -1 || x[h%10] == -1 || x[m/10] == -1 || x[m%10] == -1)
            return false;

        const unsigned mh = x[m%10] * 10 + x[m/10], mm = x[h%10] * 10 + x[h/10];
        return mh < eh && mm < em;
    };

    while (!test(sh, sm)) {
        if (++sm == m)
            ++sh;

        sm %= m;
        sh %= h;
    }

    answer(sh, sm);
}

void test_case()
{
    unsigned h, m;
    scanf("%u %u", &h, &m);

    unsigned sh, sm;
    scanf("%2u:%2u", &sh, &sm);

    solve(h, m, sh, sm);
}

int main()
{
    unsigned t;
    scanf("%u", &t);

    while (t-- > 0)
        test_case();

    return 0;
}
