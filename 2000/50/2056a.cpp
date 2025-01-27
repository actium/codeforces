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

void solve(const std::vector<std::pair<unsigned, unsigned>>& d, unsigned m)
{
    const size_t n = d.size();

    unsigned dx = m, dy = m;
    for (size_t i = 1; i < n; ++i) {
        dx += d[i].first;
        dy += d[i].second;
    }

    answer(2 * dx + 2 * dy);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> d(n);
    std::cin >> d;

    solve(d, m);
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
