#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& a, size_t k, size_t d)
{
    const size_t n = a.size();

    std::map<unsigned, unsigned> f;

    unsigned c = 0;
    for (size_t i = 0; i < d; ++i) {
        const unsigned x = a[i];
        if (f[x-1]++ == 0)
            ++c;
    }

    unsigned y = c;
    for (size_t i = d; i < n; ++i) {
        if (a[i] == a[i-d])
            continue;

        const unsigned p = a[i-d];
        if (--f[p-1] == 0)
            --c;

        const unsigned q = a[i];
        if (f[q-1]++ == 0)
            ++c;

        if (c < y)
            y = c;
    }

    answer(y);
}

void test_case()
{
    size_t n, k, d;
    std::cin >> n >> k >> d;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

