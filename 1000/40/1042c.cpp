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

void multiply(size_t& x, size_t& y)
{
    std::cout << 1 << ' ' << 1+x << ' ' << 1+y << '\n';
    x = y;
}

void drop(size_t x)
{
    std::cout << 2 << ' ' << 1+x << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<size_t> p[3];
    for (size_t i = 0; i < n; ++i)
        p[(a[i]==0)+(a[i]>=0)].push_back(i);

    for (size_t i = 0; i < 2; ++i)
        std::sort(p[i].begin(), p[i].end(), [&](size_t i, size_t j) { return a[i] < a[j]; });

    if (p[0].size() % 2 == 1) {
        p[2].push_back(p[0].back());
        p[0].pop_back();
    }

    for (size_t i = 0; i < 3; ++i) {
        while (p[i].size() > 1) {
            multiply(p[i].back(), p[i].front());
            p[i].pop_back();
        }
    }

    if (!p[2].empty() && p[0].size() + p[1].size() != 0)
        drop(p[2].back());

    if (p[0].size() + p[1].size() == 2)
        multiply(p[0].back(), p[1].back());
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}