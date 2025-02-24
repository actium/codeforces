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

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    if (k < n) {
        for (size_t i = 0; i <= n - k; ++i) {
            if (a[i+1] != 1)
                return answer(1);
        }
        return answer(2);
    }

    for (size_t i = 1; i < n; i += 2) {
        const unsigned x = (i + 1) / 2;
        if (a[i] != x)
            return answer(x);
    }

    answer(n / 2 + 1);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

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
