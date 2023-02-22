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
    std::cout << 1 + x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned f = 0;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 2)
            ++f;
    }

    if (f % 2 != 0)
        return no_answer();

    size_t x = 0;
    for (unsigned k = 0; k < f; ++x) {
        if (a[x] == 2)
            k += 2;
    }

    answer(x - (f != 0));
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
