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

void solve(const std::vector<unsigned>& t, size_t k, size_t d, size_t w)
{
    const size_t n = t.size();

    unsigned q = 0;
    for (size_t i = 0, j = 0; i < n; i = j) {
        ++q;
        while (j < n && j - i < k && t[j] - t[i] <= d + w)
            ++j;
    }

    answer(q);
}

void test_case()
{
    size_t n, k, d, w;
    std::cin >> n >> k >> d >> w;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t, k, d, w);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
