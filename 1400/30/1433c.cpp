#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(size_t v)
{
    std::cout << 1+v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const auto [min, max] = std::minmax_element(a.cbegin(), a.cend());
    if (*min == *max)
        return no_answer();

    for (auto it = std::next(max); it != a.cend(); ++it) {
        if (*it < *max)
            return answer(std::prev(it) - a.cbegin());
    }
    for (auto it = max; it != a.cbegin(); --it) {
        if (*std::prev(it) < *max)
            return answer(it - a.cbegin());
    }
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

