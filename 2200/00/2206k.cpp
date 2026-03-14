#include <array>
#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

bool check(std::array<unsigned, 10> f, unsigned k)
{
    const auto consume = [&](unsigned i, unsigned j, unsigned d) {
        f[i] -= d;
        f[j] -= d;
        return d;
    };

    unsigned h = 0;
    for (unsigned i = 9; i > 0; --i) {
        const unsigned d = std::min(f[0], f[i]);
        h += consume(0, i, std::min(d, k - h));
    }
    for (unsigned i = 0; i < 2; ++i)
        h += consume(i, i, std::min(k - h, f[i] / 2));

    unsigned m = 0;
    for (unsigned i = 0, j = 9; i < 6 && j > i; i += (f[i] == 0), j -= (f[j] == 0)) {
        const unsigned d = std::min(f[i], f[j]);
        m += consume(i, j, d);
    }
    for (unsigned i = 0; i < 6; ++i)
        m += consume(i, i, f[i] / 2);

    return h >= k && m >= k;
}

void solve(const std::string& s)
{
    std::array<unsigned, 10> f = {};
    for (const char c : s)
        ++f[c-'0'];

    unsigned lb = 0, ub = f[0] + f[1] + 1;
    while (ub - lb > 1) {
        const unsigned mid = (lb + ub) / 2;
        (check(f, mid) ? lb : ub) = mid;
    }

    answer(lb);
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
