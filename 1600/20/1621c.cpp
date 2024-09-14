#include <iostream>
#include <vector>

unsigned query(unsigned x)
{
    std::cout << '?' << ' ' << x << std::endl;

    unsigned r;
    std::cin >> r;
    return r;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << '!';
    for (const unsigned x : v)
        std::cout << ' ' << x;

    std::cout << std::endl;
}

void solve(size_t n)
{
    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i) {
        if (p[i] != 0)
            continue;

        const unsigned x = query(i+1);

        unsigned q = x;
        do {
            p[q-1] = query(i+1);
            q = p[q-1];
        } while (q != x);
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    solve(n);
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
