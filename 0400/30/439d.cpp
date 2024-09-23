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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const auto count = [&](unsigned x) {
        integer k = 0;
        for (const unsigned v : a) {
            if (v < x)
                k += x - v;
        }
        for (const unsigned v : b) {
            if (v > x)
                k += v - x;
        }
        return k;
    };

    unsigned lb = 1, ub = 1000000000;
    while (ub - lb > 5) {
        const unsigned mid1 = lb + (ub - lb) / 3, mid2 = ub - (ub - lb) / 3;
        count(mid1) < count(mid2) ? ub = mid2 : lb = mid1;
    }

    integer k = count(ub);
    for (unsigned i = lb; i < ub; ++i)
        k = std::min(k, count(i));

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
