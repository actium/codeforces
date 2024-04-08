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

    std::vector<unsigned> p(1 + n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + (s[i] - '0');

    const auto check = [&](unsigned k) {
        unsigned z = 0;
        for (size_t i = 0, j = 0; i < n; ++i) {
            while (j == i || j < n && z < k)
                z += (s[j++] == '0');

            while (j < n && s[j] == '1')
                ++j;

            if (p[i] + p[n] - p[j] <= k)
                return true;

            z -= (s[i] == '0');
        }
        return false;
    };

    int lb = -1, ub = n;
    while (lb + 1 < ub) {
        const int mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

void test_case()
{
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
