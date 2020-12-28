#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const auto& p : v)
        std::cout << p.first << ' ' << p.second << '\n';
}

void solve(unsigned n)
{
    const auto cd = [](unsigned a, unsigned d) {
        return (a + d - 1) / d;
    };

    std::vector<std::pair<unsigned, unsigned>> p;

    unsigned r = n;
    for (unsigned x = n-1; x > 2; ) {
        if (cd(r, x) < x) {
            p.emplace_back(x, n);
            --x;
        } else {
            p.emplace_back(n, x);
            r = cd(r, x);
        }
    }
    while (r != 1) {
        p.emplace_back(n, 2);
        r = cd(r, 2);
    }

    answer(p);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

