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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::vector<std::string>& t)
{
    const size_t n = s.length();

    bool v[26] = {};
    for (const char c : s) {
        if (c != '*')
            v[c - 'a'] = true;
    }

    const auto check = [&](const std::string& q) {
        for (size_t i = 0; i < n; ++i) {
            if (q[i] == s[i])
                continue;

            if (s[i] != '*' || v[q[i]-'a'])
                return false;
        }
        return true;
    };

    std::vector<std::string> r;
    for (const std::string& q : t) {
        if (check(q))
            r.push_back(q);
    }

    const auto search = [&](char x) {
        for (const std::string& q : r) {
            if (q.find(x) == std::string::npos)
                return false;
        }
        return true;
    };

    unsigned k = 0;
    for (size_t i = 0; i < 26; ++i) {
        if (!v[i] && search('a' + i))
            ++k;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    size_t m;
    std::cin >> m;

    std::vector<std::string> t(m);
    std::cin >> t;

    solve(s, t);

    return 0;
}
