#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& s)
{
    const size_t n = s.size();

    std::vector<std::pair<unsigned, unsigned>> p(1 + n, { 0, oo });
    for (size_t i = 0; i < n; ++i) {
        p[i+1].first = std::max(p[i].first, s[i].first);
        p[i+1].second = std::min(p[i].second, s[i].second);
    }

    unsigned d = 0;
    {
        std::pair<unsigned, unsigned> x = { 0, oo };
        for (size_t i = n-1; ~i != 0; --i) {
            const unsigned u = std::max(x.first, p[i].first), v = std::min(x.second, p[i].second);
            d = std::max(d, u < v ? v - u : 0);

            x.first = std::max(x.first, s[i].first);
            x.second = std::min(x.second, s[i].second);
        }
    }
    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
