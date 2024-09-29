#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::map<unsigned, size_t> x;
    for (size_t i = 0; i < n; ++i)
        x[a[i]] = i + 1;

    unsigned k = 1;
    for (size_t i = 0, b = 1; i < n; ++i) {
        if (i == b)
            k = k * 2 % M;

        b = std::max(b, x[a[i]]);
    }

    answer(k);
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
