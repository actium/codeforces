#include <iostream>
#include <numeric>
#include <string>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(const std::string& s, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    unsigned f[2] = {};
    for (const char c : s)
        ++f[c == '+'];

    const auto query = [&](unsigned a, unsigned b) {
        if (a > b)
            std::swap(a, b);

        unsigned u = f[0], v = f[1];
        if (u < v)
            std::swap(u, v);

        const unsigned d = std::gcd(a, b), x = b / d, y = a / d;
        for (unsigned i = x, j = y; i <= u && j <= v; i += x, j += y) {
            if (u - i == v - j)
                return true;
        }
        return false;
    };

    for (const std::pair<unsigned, unsigned>& q : r)
        answer(f[0] == f[1] || query(q.first, q.second));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    size_t q;
    std::cin >> q;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(s, r);

    return 0;
}
