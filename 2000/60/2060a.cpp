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

void solve(const std::vector<int>& a)
{
    const auto count = [&](int x) {
        return (a[0] + a[1] == x) + (a[1] + x == a[2]) + (x + a[2] == a[3]);
    };

    answer(std::max(count(a[2] - a[1]), count(a[3] - a[2])));
}

void test_case()
{
    std::vector<int> a(4);
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
