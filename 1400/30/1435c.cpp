#include <algorithm>
#include <iostream>
#include <set>
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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = b.size();

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    std::set<std::pair<unsigned, size_t>> h;
    for (size_t i = 0; i < n; ++i)
        h.emplace(b[i] - a[0], i);

    unsigned v = h.rbegin()->first - h.begin()->first;

    std::vector<size_t> p(n);
    while (p[h.begin()->second] < 6) {
        const size_t x = h.begin()->second;
        h.erase(h.begin());

        const unsigned d = b[x] - a[++p[x]];
        h.emplace(d, x);

        v = std::min(v, h.rbegin()->first - h.begin()->first);
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::vector<unsigned> a(6);
    std::cin >> a;

    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b);

    return 0;
}
