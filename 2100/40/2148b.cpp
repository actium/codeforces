#include <iostream>
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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned x, unsigned y)
{
    answer(a.size() + b.size());
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned x, y;
    std::cin >> x >> y;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b, x, y);
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
