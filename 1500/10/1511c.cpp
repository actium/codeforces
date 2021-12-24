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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& t)
{
    const size_t n = a.size(), q = t.size();

    std::vector<size_t> p(1 + *std::max_element(a.cbegin(), a.cend()), n);
    for (size_t i = 0; i < n; ++i) {
        const unsigned c = a[i];
        if (p[c] == n)
            p[c] = i;
    }

    std::vector<unsigned> r(q);
    for (size_t i = 0; i < q; ++i) {
        const unsigned c = t[i];
        r[i] = 1 + p[c];

        for (size_t& x : p) {
            if (x < p[c])
                ++x;
        }
        p[c] = 0;
    }

    answer(r);
}

int main()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n), t(q);
    std::cin >> a >> t;

    solve(a, t);

    return 0;
}
