#include <iostream>
#include <numeric>
#include <vector>

using integer = long long;

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

void solve(std::vector<integer>& a)
{
    integer s = std::accumulate(a.begin(), a.end(), 0);
    for (size_t k = a.size(); k > 1; --k) {
        std::vector<integer> b(k-1);
        for (size_t i = 1; i < k; ++i)
            b[i-1] = a[i] - a[i-1];

        std::swap(a, b);

        s = std::max(s, std::abs(std::accumulate(a.begin(), a.end(), 0LL)));
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n);
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
