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

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t n, const std::vector<unsigned>& d, const std::vector<unsigned>& x)
{
    const size_t m = d.size();

    std::vector<unsigned> c(m);
    for (size_t i = 0; i < m; ++i) {
        for (const unsigned q : x)
            c[i] += (q % d[i] == 0);
    }

    const unsigned q = *std::min_element(c.begin(), c.end());

    std::vector<size_t> p;
    for (size_t i = 0; i < m; ++i) {
        if (c[i] == q)
            p.push_back(i);
    }

    answer(p);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> d(m);
    std::cin >> d;

    std::vector<unsigned> x(k);
    std::cin >> x;

    solve(n, d, x);

    return 0;
}

