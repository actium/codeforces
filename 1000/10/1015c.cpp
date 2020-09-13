#include <algorithm>
#include <iostream>
#include <vector>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned m)
{
    const size_t n = a.size();

    unsigned long long s = 0;

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i) {
        s += a[i];
        c[i] = a[i] - b[i];
    }

    std::sort(c.begin(), c.end());

    unsigned k = 0;
    while (s > m && !c.empty()) {
        s -= c.back();
        c.pop_back();
        ++k;
    }

    answer(s > m ? -1 : k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n), b(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> a[i] >> b[i];

    solve(a, b, m);

    return 0;
}

