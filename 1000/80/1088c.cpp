#include <iostream>
#include <vector>

struct Operation {
    unsigned t;
    unsigned i;
    unsigned x;
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

    for (const Operation x : v)
        std::cout << x.t << ' ' << x.i << ' ' << x.x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<Operation> p;
    for (size_t i = 0, d = 0; i < n; ++i) {
        const unsigned x = (2 * n - i - (a[n-1-i] + d) % n - 1) % n;
        if (x != 0) {
            p.push_back({ 1, n - i, x });
            d += x;
        }
    }
    p.push_back({ 2, n, n });

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
