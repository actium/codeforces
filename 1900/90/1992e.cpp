#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(unsigned n)
{
    std::string t = std::to_string(n);

    const size_t m = t.length();
    while (t.length() < 6)
        t += t;

    std::vector<std::pair<unsigned, unsigned>> v;
    for (unsigned a = 1; a <= 10000; ++a) {
        const unsigned ub = a * m;

        for (unsigned b = (ub <= 5 ? 1 : m * a - 5); b <= ub; ++b) {
            const std::string s = std::to_string(n * a - b);
            if (s.length() + b == a * m && t.compare(0, s.length(), s) == 0)
                v.emplace_back(a, b);
        }
    }

    answer(v);
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
