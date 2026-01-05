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

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size() - 1;

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i)
        p[i+1] < p[i] - 1 ? ++k : ++i;

    answer(k);
}

void test_case()
{
    unsigned h;
    std::cin >> h;

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    p.push_back(0);

    solve(p);
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
