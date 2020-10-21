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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned x)
{
    const size_t n = a.size();

    unsigned s = 0, k = 0;
    for (size_t i = 0; i < n; ++i) {
        s += a[i];
        if (s % x != 0)
            k = std::max<unsigned>(k, i+1);
    }
    for (size_t i = 0; i < n; ++i) {
        s -= a[i];
        if (s % x != 0)
            k = std::max<unsigned>(k, n-1-i);
    }

    k == 0 ? no_answer() : answer(k);
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

