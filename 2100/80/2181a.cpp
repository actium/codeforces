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

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::string>& s, unsigned m)
{
    const size_t n = s.size();

    unsigned p[26] = {};
    for (size_t i = 0; i < n; ++i) {
        for (const char c : s[i])
            ++p[c-'A'];
    }

    const auto check = [&](const unsigned d[26], unsigned k) {
        for (size_t i = 0; i < 26; ++i) {
            if (d[i] != 0 && (p[i] - d[i]) * (m - k) < d[i])
                return false;
        }
        return true;
    };

    std::vector<int> v(n, -1);
    for (size_t i = 0; i < n; ++i) {
        unsigned d[26] = {};
        for (const char c : s[i])
            ++d[c-'A'];

        for (int ub = m; ub - v[i] > 1; ) {
            const int mid = (v[i] + ub) / 2;
            (check(d, mid) ? v[i] : ub) = mid;
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s, m);

    return 0;
}
