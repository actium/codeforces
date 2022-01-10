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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned f[30] = {};
    for (const unsigned x : a) {
        for (unsigned i = 0; i < 30; ++i) {
            if (x & 1 << i)
                ++f[i];
        }
    }

    std::vector<unsigned> v;
    for (unsigned k = 1; k <= n; ++k) {
        if (std::all_of(std::begin(f), std::end(f), [k](unsigned x) { return x % k == 0; }))
            v.push_back(k);
    }

    answer(v);
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
