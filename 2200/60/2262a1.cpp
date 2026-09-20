#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size();

    char separator = '\n';
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = ' ';
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<int> d(1+n);
    for (size_t i = 0; i < n; ++i) {
        const size_t k = 1 + i, lb = a[i] * k, ub = lb + k;
        ++d[std::min(lb, n)];
        --d[std::min(ub, n)];
    }

    std::vector<unsigned> b;
    for (size_t i = 0; i < n; ++i) {
        if (d[i] == 0)
            b.push_back(i);

        d[i+1] += d[i];
    }

    answer(b);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
