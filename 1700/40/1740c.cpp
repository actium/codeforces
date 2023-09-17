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

void solve(std::vector<unsigned>& a)
{
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());

    const size_t n = a.size();

    if (n == 1)
        return answer(0);

    if (n == 2)
        return answer(2 * (a[1] - a[0]));

    unsigned x = 0;
    for (size_t i = 1; i < n; ++i) {
        x = std::max(x, a[i] - a[i-1] + a[i] - a[0]);
        x = std::max(x, a[i] - a[i-1] + a[n-1] - a[i-1]);
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
