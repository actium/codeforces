#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<int>& v)
{
    std::cout << "YES" << '\n';
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }

    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<int>& a)
{
    int u = 0;
    for (const int x : a) {
        if (x < 0)
            return no_answer();

        u = std::max(u, x);
    }

    std::vector<int> b(1 + u);
    std::iota(b.begin(), b.end(), 0);
    answer(b);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
