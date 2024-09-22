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

void solve(const std::vector<unsigned>& a, size_t m, size_t w)
{
    const size_t n = a.size();

    const auto check = [&](unsigned x) {
        std::vector<int> d(1+n);
        for (size_t i = 0, k = 0; i < n; ++i) {
            d[i+1] += d[i];
            if (a[i] + d[i+1] >= x)
                continue;

            const unsigned c = x - (a[i] + d[i+1]);
            k += c;
            if (k > m)
                return false;

            d[i+1] += c;
            if (i + w < n)
                d[i+w+1] -= c;
        }
        return true;
    };

    unsigned lb = 1, ub = 1000000000 + m + 1;
    while (ub - lb > 1) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, w;
    std::cin >> n >> m >> w;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m, w);

    return 0;
}
