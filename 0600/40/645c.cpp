#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0')
            p.push_back(i);
    }

    const auto check = [&](size_t z) {
        size_t lb = z - k, ub = z;
        while (lb + 1 < ub) {
            const size_t mid = (lb + ub) / 2;
            if (p[mid] - p[z-k] == p[z] - p[mid])
                return p[z] - p[mid];

            if (p[mid] - p[z-k] > p[z] - p[mid])
                ub = mid;
            else
                lb = mid;
        }
        return std::min(std::max(p[lb] - p[z-k], p[z] - p[lb]), std::max(p[ub] - p[z-k], p[z] - p[ub]));
    };

    unsigned d = ~0u;
    for (size_t i = k; i < p.size(); ++i)
        d = std::min<unsigned>(d, check(i));

    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}
