#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned h, unsigned k)
{
    const size_t n = a.size();

    integer t = 0;

    unsigned c = h;
    for (size_t i = 0; i < n; ++i) {
        if (c < a[i]) {
            const unsigned d = (a[i] - c + k - 1) / k;
            t += d;
            c += std::min(h - c, k * d);
        }
        c -= a[i];
    }

    t += (h - c + k - 1) / k;

    answer(t);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned h, k;
    std::cin >> h >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, h, k);

    return 0;
}
