#include <iostream>
#include <vector>

using position_t = std::pair<unsigned, unsigned>;

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

void solve(size_t n, const std::vector<position_t>& p)
{
    answer(p.size() < n);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<position_t> p(m);
    std::cin >> p;

    solve(n, p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
