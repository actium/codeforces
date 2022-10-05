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

unsigned traverse(const std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<unsigned>& d,
        const std::vector<size_t>& x, size_t i, std::vector<bool>& v)
{
    const unsigned q = (d[i] != 0 || a[i] == b[i] ? 1 : 2);
    if (!v[i]) {
        v[i] = true;
        return std::min(q, traverse(a, b, d, x, x[b[i]], v));
    }
    return q;
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<unsigned>& d)
{
    const size_t n = a.size();

    unsigned k = 1;

    std::vector<size_t> x(1+n);
    for (size_t i = 0; i < n; ++i)
        x[a[i]] = i;
    
    std::vector<bool> v(n);
    for (size_t i = 0; i < n; ++i) {
        if (v[i])
            continue;

        k = k * traverse(a, b, d, x, i, v) % 1000000007;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n), d(n);
    std::cin >> a >> b >> d;

    solve(a, b, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
