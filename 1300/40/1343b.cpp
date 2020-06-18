#include <iostream>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

template <typename T>
void answer(const std::vector<T>& v)
{
    const char* separator = "";
    for (const T a : v) {
        std::cout << separator << a;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t n)
{
    const size_t k = n / 2;
    if (k % 2 != 0)
        return answer(false);

    std::vector<unsigned> v;
    for (size_t i = 1; i <= k; ++i)
        v.push_back(2 * i);

    for (size_t i = 0; i < k - 1; ++i)
        v.push_back(2 * i + 1);

    v.push_back(3 * k - 1);

    answer(true);
    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

