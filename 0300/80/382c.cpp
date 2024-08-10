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

void answer(const std::set<int>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void infinity()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    if (n == 1)
        return infinity();

    std::set<int> v;
    if (n == 2) {
        if (a[0] > a[1])
            std::swap(a[0], a[1]);

        const unsigned d = a[1] - a[0];
        if (d % 2 == 0)
            v.insert(a[0] + d / 2);

        v.insert(a[0] - d);
        v.insert(a[1] + d);
    } else {
        std::sort(a.begin(), a.end());

        unsigned d = ~0u;
        for (size_t i = 1; i < n; ++i)
            d = std::min(d, a[i] - a[i-1]);

        for (size_t i = 1; i < n; ++i) {
            if (a[i] - a[i-1] != d) {
                v.insert(a[i-1] + d);
                v.insert(a[i] - d);
            }
        }

        if (v.size() != 1) {
            if (v.empty()) {
                v.insert(a[0] - d);
                v.insert(a[n-1] + d);
            } else {
                v.clear();
            }
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
