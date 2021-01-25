#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t m, const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t k = a.size();

    std::vector<unsigned> fa(n), fb(m);
    for (size_t i = 0; i < k; ++i) {
        ++fa[a[i]-1];
        ++fb[b[i]-1];
    }

    unsigned long long q = 0;
    for (size_t i = 0; i < k; ++i)
        q += k - (fa[a[i]-1] + fb[b[i]-1] - 1);

    answer(q / 2);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(k), b(k);
    std::cin >> a >> b;

    solve(n, m, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

