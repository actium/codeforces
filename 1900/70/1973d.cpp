#include <iostream>

unsigned query(unsigned p, unsigned x)
{
    std::cout << '?' << ' ' << p << ' ' << x << std::endl;

    unsigned r;
    std::cin >> r;
    return r;
}

void answer(int x)
{
    std::cout << '!' << ' ' << x << std::endl;
    std::cin >> x;
}

void solve(unsigned n, unsigned k)
{
    unsigned x = n;
    while (query(1, n * x) != n)
        --x;

    for (unsigned q = n / k; q != 0; --q) {
        unsigned p = 0, c = 0;
        do {
            p = query(p + 1, q * x);
            ++c;
        } while (p < n && c < k);

        if (p == n && c == k)
            return answer(q * x);
    }

    answer(-1);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
