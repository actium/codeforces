#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

std::string check(const std::string& p, const std::vector<std::string>& s)
{
    const size_t m = s.size(), n = m / 2 + 1;

    std::string t(m, '?');
    {
        std::vector<size_t> d(m / 2);
        for (size_t i = 0; i < m; ++i) {
            const size_t k = s[i].length();

            const unsigned u = p.compare(0, k, s[i]), v = p.compare(n - k, k, s[i]);
            if (u != 0 && v != 0)
                return {};

            if (u == 0 && v == 0)
                t[i] = "PS"[d[k-1]++];
            else
                t[i] = "PS"[v == 0];
        }
    }

    unsigned f[2] = {};
    for (const char c : t)
        ++f[c == 'S'];

    if (f[0] != f[1])
        return {};

    return t;
}

void solve(const std::vector<std::string>& s)
{
    std::pair<std::string, std::string> p;
    for (const std::string& q : s) {
        if (2 * q.length() == s.size()) {
            std::swap(p.first, p.second);
            p.second = q;
        }
    }

    std::string t = check(p.first + p.second.back(), s);
    if (t.empty())
        t = check(p.second + p.first.back(), s);

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(2 * n - 2);
    std::cin >> s;

    solve(s);

    return 0;
}
