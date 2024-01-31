#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x)
{
    constexpr const char* s[2] = { "Alice", "Bob" };
    std::cout << s[x] << '\n';
}

void solve(const std::vector<int>& a)
{
    unsigned f[2] = {};
    for (const int x : a)
        ++f[abs(x) % 2];

    constexpr size_t x[] = { 0, 1, 1, 0, 0, 0, 1, 0 };
    answer(x[f[0] % 2 * 4 + f[1] % 4]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
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
