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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(size_t n, size_t k, size_t a, const std::vector<unsigned>& x)
{
    const size_t m = x.size();

    const auto check = [&](size_t q) {
        std::vector<unsigned> p(x.begin(), x.begin() + q);
        std::sort(p.begin(), p.end());

        unsigned r = 0, c = 0;
        for (const unsigned b : p) {
            c += (b - r) / (a + 1);
            r = b;
        }
        c += (n + 1 - r) / (a + 1);
        return c >= k;
    };

    if (check(m))
        return no_answer();

    unsigned lb = 0, ub = m;
    while (ub - lb > 1) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(ub);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k, a;
    std::cin >> n >> k >> a;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> x(m);
    std::cin >> x;

    solve(n, k, a, x);

    return 0;
}
