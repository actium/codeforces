#include <iostream>
#include <vector>

#include <cstdint>

constexpr uint64_t unit = 1;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<uint64_t>& s)
{
    const size_t n = s.size();

    uint64_t t = 0;
    for (const uint64_t x : s)
        t |= x;

    unsigned k = 0;
    for (unsigned i = 1; i <= 50; ++i) {
        if ((t & unit << i) == 0)
            continue;

        uint64_t q = 0;
        for (const uint64_t x : s) {
            if ((x & unit << i) == 0)
                q |= x;
        }

        k = std::max<unsigned>(k, __builtin_popcountll(q));
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<uint64_t> s(n);
    for (size_t i = 0; i < n; ++i) {
        size_t k;
        std::cin >> k;

        for (size_t j = 0; j < k; ++j) {
            unsigned x;
            std::cin >> x;

            s[i] |= unit << x;
        }
    }

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
