#include <iostream>
#include <string>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> d;
    for (size_t l = 0, r = 1; l < n; l = r++) {
        while (r < n && s[r] == s[r-1])
            ++r;

        d.push_back(r - l);
    }

    unsigned c = 0;
    for (size_t i = 0, j = 0, m = d.size(); i < m; ++i) {
        for (j = std::max(i, j); j < m && d[j] < 2; ++j);

        if (j < m)
            --d[j];
        else
            ++i;

        ++c;
    }

    answer(c);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

