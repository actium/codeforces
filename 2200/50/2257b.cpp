#include <iostream>
#include <vector>

using integer = unsigned long long;

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

integer count(const std::vector<unsigned>& v)
{
    const size_t n = v.size();

    integer s = 0;
    for (size_t i = 1; i < n; ++i)
        s += v[i-1] - v[i] + 1;
    
    return s + v.back();
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    answer(count(a) >= count(b) ? 1 : 2);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);
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
