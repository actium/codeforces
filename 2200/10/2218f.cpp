#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << "YES" << '\n';
    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned x, unsigned y)
{
    const unsigned p = (x + y) % 2;
    if (x > y || p == 0 && x == 0)
        return no_answer();

    std::vector<std::pair<unsigned, unsigned>> t;
    {
        unsigned v = 2;
        for (unsigned i = (p == 0); i < x; ++i) {
            t.emplace_back(1, v);
            t.emplace_back(v, v+1);
            v += 2;
        }
        while (v <= x + y)
            t.emplace_back(1, v++);
    }

    answer(t);
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);
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
