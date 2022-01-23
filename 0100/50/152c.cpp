#include <iostream>
#include <numeric>
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

void solve(const std::vector<std::string>& v)
{
    constexpr unsigned M = 1000000007;

    const size_t n = v.size(), m = v[0].length();

    unsigned k = 1;
    for (size_t i = 0; i < m; ++i) {
        unsigned e[26] = {};
        for (const std::string& s : v)
            e[s[i]-'A'] = 1;

        k = 1ull * k * std::accumulate(std::cbegin(e), std::cend(e), 0u) % M;
    }

    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> v(n);
    std::cin >> v;

    solve(v);

    return 0;
}
