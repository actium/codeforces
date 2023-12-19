#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) {
        return s[i] != s[j] ? s[i] > s[j] : i < j;
    });

    std::vector<size_t> q;
    for (size_t i = 0; i < n; ++i) {
        if (q.empty() || p[i] > q.back())
            q.push_back(p[i]);
    }

    std::string t = s;
    for (size_t i = 0, j = q.size(); i < n && j > 0; ++i) {
        if (p[i] == q[q.size() - j])
            t[p[i]] = s[q[--j]];
    }

    if (!std::is_sorted(t.begin(), t.end()))
        return no_answer();

    unsigned k = q.size() - 1;
    for (size_t i = 1; i < q.size() && s[q[i]] == s[q[i-1]]; ++i)
        --k;

    answer(k);
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
