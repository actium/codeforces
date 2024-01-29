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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b, unsigned m)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    const auto check = [&](size_t offset, unsigned d) {
        for (size_t i = 0; i < n; ++i) {
            if ((a[i] + d) % m != b[(offset + i) % n] % m)
                return false;
        }
        return true;
    };

    unsigned x = ~0u;
    for (size_t i = 0; i < n; ++i) {
        const unsigned d = (a[0] <= b[i] ? b[i] - a[0] : m - a[0] + b[i]);
        if (check(i, d))
            x = std::min(x, d);
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, m);

    return 0;
}
