#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned v = ~0u;
    for (size_t i = 1; i < n; ++i) {
        std::vector<unsigned> d(n-1);
        for (size_t j = 0; j < n; ++j) {
            if (j < i)
                d[j] = s[j] - '0';
            else
                d[j-1] = d[j-1] * 10 + s[j] - '0';
        }

        unsigned t = 0;
        for (const unsigned x : d) {
            if (x == 0)
                return answer(0);

            if (x != 1)
                t += x;
        }

        v = std::min(v, std::max(t, 1u));
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
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
