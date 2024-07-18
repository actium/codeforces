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

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::vector<int> da(1 + 2 * k + 1);

    const auto update = [&](unsigned lb, unsigned ub, int delta) {
        da[lb] += delta;
        da[ub+1] -= delta;
    };

    update(2, 2 * k, n);
    for (size_t i = 0, j = n-1; i < j; ++i, --j) {
        const unsigned s = a[i] + a[j];
        update(s, s, -1);

        const unsigned lb = s - (std::max(a[i], a[j]) - 1);
        const unsigned ub = s + (k - std::min(a[i], a[j]));
        update(lb, ub, -1);
    }

    unsigned x = da[2];
    for (size_t i = 3; i <= 2 * k; ++i) {
        da[i] += da[i-1];
        x = std::min<unsigned>(x, da[i]);
    }

    answer(x);
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
