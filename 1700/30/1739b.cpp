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
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& d)
{
    const size_t n = d.size();

    std::vector<unsigned> a(n);
    a[0] = d[0];
    for (size_t i = 1; i < n; ++i) {
        if (a[i-1] >= d[i] && d[i] != 0)
            return no_answer();

        a[i] = a[i-1] + d[i];
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
