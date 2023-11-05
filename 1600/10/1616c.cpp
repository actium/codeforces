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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    if (n < 3)
        return answer(0);

    const auto count = [&](int x, const std::pair<int, int>& d) {
        unsigned k = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] * d.second + d.first * (x - i) != a[x] * d.second)
                ++k;
        }
        return k;
    };

    unsigned k = ~0u;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != i)
                k = std::min(k, count(i, { a[i] - a[j], i - j }));
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);
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
