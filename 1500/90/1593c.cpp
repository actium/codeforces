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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, std::vector<unsigned>& x)
{
    const size_t k = x.size();

    std::sort(x.begin(), x.end(), std::greater<unsigned>());

    unsigned c = 0, d = 0;
    for (const unsigned q : x) {
        d += n - q;
        if (d >= n)
            break;

        ++c;
    }

    answer(c);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    size_t k;
    std::cin >> k;

    std::vector<unsigned> x(k);
    std::cin >> x;

    solve(n, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
