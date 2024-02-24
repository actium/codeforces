#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& x, unsigned k)
{
    const size_t n = x.length();

    std::vector<size_t> p[10];
    for (size_t i = 0; i < n; ++i)
        p[x[i]-'0'].push_back(i);

    std::string v;
    for (size_t i = 0; i < n; ++i) {
        for (size_t c = v.empty(), d = x[i] - '0'; c < d; ++c) {
            const auto it = std::lower_bound(p[c].begin(), p[c].end(), i);
            if (it != p[c].end() && *it - i <= k) {
                k -= *it - i;
                i = *it;
                break;
            }
        }

        v.push_back(x[i]);
    }

    v.resize(v.length() - k);

    answer(v);
}

void test_case()
{
    std::string x;
    std::cin >> x;

    unsigned k;
    std::cin >> k;

    solve(x, k);
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
