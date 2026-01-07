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

void solve(const std::vector<unsigned>& a)
{
    size_t n = a.size();

    const auto delta = [&](size_t i, size_t j) {
        return std::max(a[i], a[j]) - std::min(a[i], a[j]);
    };

    unsigned s = 0;
    for (size_t i = 1; i < n; ++i)
        s += delta(i-1, i);

    unsigned v = s - std::max(delta(0, 1), delta(n-2, n-1));
    for (size_t i = 1; i + 1 < n; ++i)
        v = std::min(v, s - delta(i-1, i) - delta(i, i+1) + delta(i-1, i+1));

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
