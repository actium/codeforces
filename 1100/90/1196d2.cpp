#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    std::string t;
    t.reserve(n + 5);
    for (size_t i = 0; i < n + 3; i += 3) {
        t.push_back('R');
        t.push_back('G');
        t.push_back('B');
    }

    unsigned q = ~0u;
    for (size_t i = 0; i < 3; ++i) {
        unsigned d = 0;
        for (size_t j = 0; j < k; ++j)
            d += (s[j] != t[i+j]);

        q = std::min(q, d);

        for (size_t j = k; j < n; ++j) {
            d -= (s[j-k] != t[i+j-k]);
            d += (s[j] != t[i+j]);
            q = std::min(q, d);
        }
    }

    answer(q);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
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
