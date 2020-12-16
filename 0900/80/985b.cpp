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

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size(), m = s[0].length();

    std::vector<unsigned> f(m);
    for (const std::string& x : s) {
        for (size_t i = 0; i < m; ++i)
            f[i] += x[i] - '0';
    }

    const auto check = [&](const std::string& x) {
        for (size_t i = 0; i < m; ++i) {
            if (x[i] == '1' && f[i] < 2)
                return false;
        }
        return true;
    };

    for (const std::string& x : s) {
        if (check(x))
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}

