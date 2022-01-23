#include <algorithm>
#include <iostream>
#include <vector>

struct Operation {
    unsigned t;
    size_t i;
    size_t j;
};

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<Operation>& v)
{
    std::cout << v.size() << '\n';

    for (const Operation& x : v)
        std::cout << x.t << ' ' << 1+x.i << ' ' << 1+x.j << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> f(1 + 200000);
    for (const unsigned x : a)
        ++f[x];

    const unsigned x = std::max_element(f.cbegin(), f.cend()) - f.cbegin();

    const size_t b = std::find(a.cbegin(), a.cend(), x) - a.cbegin();

    std::vector<Operation> p;
    for (size_t i = b; i > 0; --i) {
        if (a[i-1] < a[b])
            p.push_back({ 1, i-1, i });

        if (a[i-1] > a[b])
            p.push_back({ 2, i-1, i });
    }
    for (size_t i = b+1; i < n; ++i) {
        if (a[i] < a[b])
            p.push_back({ 1, i, i-1 });

        if (a[i] > a[b])
            p.push_back({ 2, i, i-1 });
    }

    answer(p);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
