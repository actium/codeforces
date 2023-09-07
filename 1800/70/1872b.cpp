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

void solve(const std::vector<std::pair<unsigned, unsigned>>& ds)
{
    const size_t n = ds.size();

    unsigned k = ~0u;
    for (const std::pair<unsigned, unsigned>& e : ds)
        k = std::min(k, e.first + (e.second - 1) / 2);

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> ds(n);
    std::cin >> ds;

    solve(ds);
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
