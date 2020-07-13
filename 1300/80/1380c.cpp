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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, unsigned x)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned c = 1;
        while (i < n && c * a[i] < x)
            ++i, ++c;

        if (i < n && c * a[i] >= x)
            ++k;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

