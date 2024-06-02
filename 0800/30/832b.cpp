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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& v, const std::string& t, const std::vector<std::string>& q)
{
    const size_t m = t.length();

    size_t x = 0;
    while (x < m && t[x] != '*')
        ++x;

    const auto check = [&](const std::string& s, size_t p, size_t q, size_t k) {
        for (size_t i = 0; i < k; ++i) {
            if (t[p+i] != '?' && s[q+i] != t[p+i])
                return false;

            if (t[p+i] == '?' && v.find_first_of(s[q+i]) == std::string::npos)
                return false;
        }
        return true;
    };

    for (const std::string& s : q) {
        if (x == m) {
            answer(s.length() == m && check(s, 0, 0, m));
            continue;
        }

        const size_t k = m - x - 1;
        if (s.length() < m - 1 || !check(s, 0, 0, x) || !check(s, x + 1, s.length() - k, k)) {
            answer(false);
            continue;
        }

        answer(s.substr(x, s.length() - k - x).find_first_of(v) == std::string::npos);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string v, t;
    std::cin >> v >> t;

    size_t n;
    std::cin >> n;

    std::vector<std::string> q(n);
    std::cin >> q;

    solve(v, t, q);

    return 0;
}
