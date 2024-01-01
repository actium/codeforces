#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<unsigned>& b, size_t k)
{
    unsigned long long p = 1;
    for (const unsigned x : b)
        p *= x;

    if (2023 % p != 0)
        return no_answer();

    std::vector<unsigned> a(k, 1);
    a[0] = 2023 / p;
    answer(a);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(b, k);
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
