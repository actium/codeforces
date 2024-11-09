#include <algorithm>
#include <iostream>
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

void solve(size_t n, std::vector<std::pair<unsigned, unsigned>>& p)
{
    const size_t k = p.size();

    std::vector<unsigned> c(1+k);
    for (size_t i = 0; i < k; ++i)
        c[p[i].first] += p[i].second;

    std::sort(c.begin(), c.end(), std::greater<unsigned>());

    unsigned s = 0;
    for (size_t i = 0; i < std::min(n, k); ++i)
        s += c[i];

    answer(s);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::pair<unsigned, unsigned>> p(k);
    std::cin >> p;

    solve(n, p);
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
