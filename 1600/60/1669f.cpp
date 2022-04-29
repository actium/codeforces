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

void solve(const std::vector<unsigned>& w)
{
    const size_t n = w.size();

    unsigned a = 0, b = 0, k = 0;
    for (size_t i = 0, j = n-1; i <= j; ++i) {
        for (a += w[i]; b < a && j > i; --j)
            b += w[j];

        if (a == b)
            k = i + n - j;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> w(n);
    std::cin >> w;

    solve(w);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

