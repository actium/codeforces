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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

unsigned count(unsigned s, unsigned t, unsigned d)
{
    return t - s >= d ? t - s - d + 1 : 0;
}

void solve(std::vector<unsigned>& a, size_t k, unsigned x)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    const auto check = [&](unsigned d) {
        unsigned c = count(0, a[0], d) + count(a[n-1], x, d);
        for (size_t i = 1; i < n && c < k; ++i)
            c += count(a[i-1], a[i], 2 * d);

        return c >= k;
    };

    unsigned lb = 0, ub = x + 1;
    while (ub - lb > 1) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    std::vector<unsigned> t;
    if (lb == 0) {
        for (unsigned p = 0; p < k; ++p)
            t.push_back(p);
    } else {
        for (unsigned p = 0; p + lb <= a[0] && t.size() < k; ++p)
            t.push_back(p);

        for (size_t i = 1; i < n && t.size() < k; ++i) {
            for (unsigned p = a[i-1] + lb; p + lb <= a[i] && t.size() < k; ++p)
                t.push_back(p);
        }

        for (unsigned p = a[n-1] + lb; p <= x && t.size() < k; ++p)
            t.push_back(p);
    }

    answer(t);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k, x);
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
