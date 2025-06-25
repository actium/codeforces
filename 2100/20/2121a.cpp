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

void solve(const std::vector<unsigned>& x, unsigned s)
{
    const auto distance = [](unsigned s, unsigned t) {
        return std::max(s, t) - std::min(s, t);
    };

    const unsigned d1 = distance(s, x.front()), d2 = distance(s, x.back());

    answer(distance(x.front(), x.back()) + std::min(d1, d2));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x, s);
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
