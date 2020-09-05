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

void solve(std::vector<unsigned>& x, unsigned k)
{
    const size_t n = x.size();

    std::sort(x.begin(), x.end());

    std::vector<unsigned> pm(n);
    for (size_t l = 0, r = 0, m = 0; r < n; ++r) {
        while (x[r] - x[l] > k)
            ++l;

        m = std::max(m, r - l + 1);
        pm[r] = m;
    }

    std::vector<unsigned> sm(n);
    for (size_t l = n-1, r = n-1, m = 0; ~l; --l) {
        while (x[r] - x[l] > k)
            --r;

        m = std::max(m, r - l + 1);
        sm[l] = m;
    }

    unsigned c = 1;
    for (size_t i = 0; i < n-1; ++i)
        c = std::max(c, pm[i] + sm[i+1]);

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> x(n);
    std::cin >> x;

    std::vector<unsigned> y(n);
    std::cin >> y;

    solve(x, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

