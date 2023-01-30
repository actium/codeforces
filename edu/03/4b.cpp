#include <iostream>
#include <string>
#include <vector>

void answer(size_t x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t m = s.length(), n = 3 * m + 1;

    std::string v;
    v.reserve(n);
    v.append(t); v.push_back(' '); v.append(s); v.append(s);

    std::vector<unsigned> z(n);
    for (size_t i = 1, j = 0; i < n; ++i) {
        unsigned& p = z[i];
        if (j + z[j] > i)
            p = std::min<unsigned>(j + z[j] - i, z[i - j]);

        while (i + p < n && v[p] == v[i + p])
            ++p;

        if (j + z[j] < i + p)
            j = i;
    }

    for (size_t i = m + 1; i < n; ++i) {
        if (z[i] >= m)
            return answer(i - (m + 1));
    }

    no_answer();
}

void test_case()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
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
