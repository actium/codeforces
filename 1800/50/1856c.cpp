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

bool test(const std::vector<unsigned>& a, size_t b, unsigned x, unsigned k)
{
    if (b == a.size())
        return false;

    if (a[b] >= x)
        return true;

    if (x - a[b] > k)
        return false;

    return test(a, b + 1, x - 1, k - (x - a[b]));
}

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    const auto check = [&](unsigned x) {
        for (size_t i = 0; i < n; ++i) {
            if (test(a, i, x, k))
                return true;
        }
        return false;
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

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
