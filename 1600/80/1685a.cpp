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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size(), m = n / 2;
    if (n % 2 == 1)
        return no_answer();

    std::sort(a.begin(), a.end());

    std::vector<unsigned> b;
    for (size_t i = 0; i < m; ++i) {
        if (a[i] == a[i+m] || (i+1 < m && a[i+1] == a[i+m]))
            return no_answer();

        b.push_back(a[i]);
        b.push_back(a[i+m]);
    }

    answer(b);
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
