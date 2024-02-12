#include <iostream>
#include <string>

std::string sum(const std::string& lhs, const std::string& rhs)
{
    const size_t n = lhs.length(), m = rhs.length();

    std::string value(lhs.rbegin(), lhs.rend());
    value.resize(std::max(n, m) + 1, '0');

    for (size_t i = 0; i < m; ++i) {
        value[i] += rhs[m-1-i] - '0';
        if (value[i] > '9') {
            value[i] -= 10;
            ++value[i+1];
        }
    }

    for (size_t i = m; value[i] > '9'; ++i) {
        value[i] -= 10;
        ++value[i+1];
    }

    if (value.length() > 1 && value.back() == '0')
        value.pop_back();

    return std::string(value.rbegin(), value.rend());
}

std::string select_min(const std::string& lhs, const std::string& rhs)
{
    if (lhs.length() < rhs.length())
        return lhs;

    if (rhs.length() < lhs.length())
        return rhs;

    return std::min(lhs, rhs);
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::string v(n, '9');

    size_t p = (n + 1) / 2;
    while (p < n && s[p] == '0')
        ++p;

    if (p < n)
        v = select_min(v, sum(s.substr(0, p), s.substr(p)));

    size_t q = (n - 1) / 2;
    while (q > 0 && s[q] == '0')
        --q;

    if (q > 0)
        v = select_min(v, sum(s.substr(0, q), s.substr(q)));

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t l;
    std::cin >> l;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
