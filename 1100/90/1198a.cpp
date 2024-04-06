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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, unsigned m)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<unsigned> b = { 0, 1 };
    for (size_t i = 1; i < n; ++i) {
        if (a[i] != a[i-1])
            b.push_back(b.back());

        ++b.back();
    }

    const unsigned k = std::min<unsigned>(20, 8 * m / n), q = 1 << k;
    if (k >= b.size() || q >= n)
        return answer(0);

    unsigned x = n;
    for (size_t i = q; i < b.size(); ++i)
        x = std::min(x, b[i-q] + b.back() - b[i]);

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);

    return 0;
}
