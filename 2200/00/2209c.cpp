#include <iostream>

unsigned query(unsigned i, unsigned j)
{
    std::cout << '?' << ' ' << i << ' ' << j << std::endl;

    int r;
    std::cin >> r;
    return r;
}

void answer(unsigned k)
{
    std::cout << '!' << ' ' << k << std::endl;
}

void solve(unsigned n)
{
    for (unsigned i = 2; i < 2 * n; i += 2) {
        if (query(i, i + 1) == 1)
            return answer(i);
    }

    answer(query(1, 2) == 1 || query(1, 3) == 1 ? 1 : 2 * n);
}

void test_case()
{
    unsigned n;
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
