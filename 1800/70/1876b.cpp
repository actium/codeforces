#include <algorithm>
#include <iostream>
#include <vector>

constexpr unsigned M = 998244353;

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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i; j < n; j += i + 1)
            a[i] = std::max(a[i], a[j]);
    }

    std::sort(a.begin(), a.end());

    unsigned v = 0, p = 1;
    for (size_t i = 0; i < n; ++i) {
        v = (v + 1ull * a[i] * p) % M;
        p = p * 2ull % M;
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
