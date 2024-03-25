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

void solve(const std::vector<unsigned>& h)
{
    const size_t n = h.size();

    const auto check = [&](unsigned x) {
        unsigned d[2] = {};
        for (size_t i = n - 1; i > 1; --i) {
            if (h[i] + d[1] < x)
                return false;

            const unsigned t = std::min(h[i], h[i] + d[1] - x) / 3;
            d[1] = d[0] + t;
            d[0] = 2 * t;
        }
        return h[0] + d[0] >= x && h[1] + d[1] >= x;
    };

    unsigned lb = 0, ub = ~0u;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
