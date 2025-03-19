#include <iostream>
#include <numeric>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& c)
{
    const size_t n = c.size();

    unsigned k = 1;
    {
        unsigned long long g = 1ull * c[0].first * c[0].second, m = c[0].second;
        for (size_t i = 1; i < n; ++i) {
            g = std::gcd(g, 1ull * c[i].first * c[i].second);
            m = std::lcm(m, c[i].second);
            if (g % m != 0) {
                g = 1ull * c[i].first * c[i].second;
                m = c[i].second;
                ++k;
            }
        }
    }
    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> c(n);
    std::cin >> c;

    solve(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
