#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(long long v)
{
    std::cout << v << '\n';
}

void solve(std::array<std::vector<unsigned>, 3>& a)
{
    for (auto& v : a)
        sort(v.begin(), v.end());

    long long s[3] = {}, t = 0;
    for (size_t i = 0; i < 3; ++i) {
        s[i] = std::accumulate(a[i].begin(), a[i].end(), 0ll);
        t += s[i];
    }

    long long b = -t;
    for (size_t i = 0; i < 3; ++i) {
        const size_t j = (i + 1) % 3, k = (i + 2) % 3;

        b = std::max(b, t - 2 * (a[j][0] + a[k][0]));
        b = std::max(b, t - 2 * s[i]);
    }

    answer(b);
}

int main()
{
    std::array<std::vector<unsigned>, 3> a;

    for (size_t i = 0; i < 3; ++i) {
        size_t n;
        std::cin >> n;

        a[i].resize(n);
    }

    for (size_t i = 0; i < 3; ++i)
        std::cin >> a[i];

    solve(a);

    return 0;
}

