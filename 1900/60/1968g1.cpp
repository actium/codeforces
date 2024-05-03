#include <iostream>
#include <string>
#include <vector>

template <typename T = std::string_view>
std::vector<unsigned> Z(T&& s)
{
    const unsigned n = s.size();

    std::vector<unsigned> z(n);
    for (unsigned i = 1, j = 0; i < n; ++i) {
        if (i < j + z[j])
            z[i] = std::min(j + z[j] - i, z[i-j]);

        while (i + z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];

        if (j + z[j] < i + z[i])
            j = i;
    }
    z[0] = n;
    return z;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, unsigned k)
{
    const size_t n = s.length();

    const std::vector<unsigned> z = Z(s);

    const auto check = [&](unsigned p) {
        unsigned q = 1;
        for (size_t i = p; i < n; ++i) {
            if (z[i] >= p) {
                ++q;
                i += p - 1;
            }
        }
        return q >= k;
    };

    unsigned lb = 0, ub = n / k + 1;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned l, r;
    std::cin >> l >> r;

    std::string s;
    std::cin >> s;

    solve(s, l);
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
