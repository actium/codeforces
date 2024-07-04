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

void solve(const std::vector<unsigned>& h)
{
    unsigned t = 0;
    for (auto it = h.rbegin(); it != h.rend(); ++it)
        t = std::max(*it, t + 1);

    answer(t);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h);
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
