#include <iostream>
#include <map>
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

void solve(const std::vector<std::pair<unsigned, unsigned>>& c)
{
    const size_t n = c.size() - 1;

    std::map<unsigned, unsigned> f;
    for (const auto& p : c)
        ++f[p.first];

    for (const auto& p : c) {
        const unsigned k = n - f[p.second];
        std::cout << 2 * n - k << ' ' << k << '\n';
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> c(n);
    std::cin >> c;

    solve(c);

    return 0;
}

