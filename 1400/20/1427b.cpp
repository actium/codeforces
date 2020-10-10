#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::string& s, unsigned k)
{
    const size_t n = s.length();

    std::vector<std::pair<size_t, size_t>> d;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            if (i == 0 || s[i-1] == 'W')
                d.emplace_back(i, i);

            ++d.back().second;
        }
    }

    if (!d.empty() && d.front().first == 0)
        d.erase(d.begin());

    const auto comparator = [](const std::pair<size_t, size_t>& a, const std::pair<size_t, size_t>& b) {
        const size_t da = a.second - a.first;
        const size_t db = b.second - b.first;
        return da == db ? a.first < b.first : da < db;
    };
    std::sort(d.begin(), d.end(), comparator);

    for (auto it = d.begin(); it != d.end(); ++it) {
        if (it->second == n) {
            const auto x = *it;
            d.erase(it);
            d.push_back(x);
            break;
        }
    }

    for (const auto& p : d) {
        for (size_t i = p.first; i < p.second && k > 0; ++i, --k)
            s[i] = 'W';
    }
    for (size_t i = n; i-- > 0 && k > 0; ) {
        if (s[i] == 'L') {
            s[i] = 'W';
            --k;
        }
    }

    unsigned c = (s[0] == 'W');
    for (size_t i = 1; i < n; ++i) {
        if (s[i] == 'W')
            c += 1 + (s[i-1] == 'W');
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

