#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& c, const std::vector<unsigned>& q)
{
    const size_t n = c.size();

    integer t = 0;
    for (const unsigned x : c)
        t += x;

    integer s = 0;
    for (const unsigned x : q) {
        t -= c[x-1];
        s += t * c[x-1];
    }

    for (size_t i = 0; i < n; ++i) {
        if (std::binary_search(q.cbegin(), q.cend(), 1+i))
            continue;

        const size_t j = (i + 1) % n;
        if (std::binary_search(q.cbegin(), q.cend(), 1+j))
            continue;

        s += c[i] * c[j];
    }

    answer(s);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> c(n);
    std::cin >> c;

    std::vector<unsigned> q(k);
    std::cin >> q;

    solve(c, q);

    return 0;
}
