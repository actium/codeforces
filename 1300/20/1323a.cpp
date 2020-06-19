#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(size_t k, size_t x)
{
    answer(k);

    std::cout << 1 + x << '\n';
}

void answer(size_t k, size_t x, size_t y)
{
    answer(k);

    std::cout << 1 + x << ' ' << 1 + y << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    for (size_t i = 0; i < n; ++i) {
        if (a[i] % 2 == 0)
            return answer(1, i);
    }

    if (n == 1)
        answer(-1);
    else
        answer(2, 0, 1);
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

