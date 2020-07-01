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

void solve(std::vector<unsigned>& a, size_t x)
{
    const size_t n = a.size();

    std::vector<bool> b(n + x);
    for (size_t i = 0; i < n; ++i) {
        b[a[i]-1] = true;
    }

    size_t v = 0;
    while (v < b.size() && (b[v] || x-- > 0))
        ++v;

    answer(v);
}

void test_case()
{
    size_t n, x;
    std::cin >> n >> x;

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

