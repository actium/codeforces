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
    std::cout << "Yes" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "No" << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t x = 0, y = 0;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] > a[x])
            x = i;

        if (a[i] < a[y])
            y = i;
    }

    if (x == y)
        return no_answer();

    for (size_t i = 0; i < n; ++i)
        a[i] = 1 + (i == x);

    answer(a);
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
