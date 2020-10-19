#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t k = n + 1;

    std::vector<size_t> p(n, n);
    for (size_t i = 0; i < n; ++i) {
        const unsigned x = a[i] - 1;
        if (p[x] < i)
            k = std::min(k, i - p[x] + 1);

        p[x] = i;
    }

    k <= n ? answer(k) : no_answer();
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

