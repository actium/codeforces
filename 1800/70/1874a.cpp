#include <algorithm>
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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b, size_t k)
{
    k = 2 + k % 2;

    for (size_t i = 0; i < k; ++i) {
        if (i % 2 == 0) {
            const auto it = std::min_element(a.begin(), a.end());
            const auto jt = std::max_element(b.begin(), b.end());
            if (*it < *jt)
                std::swap(*it, *jt);
        } else {
            const auto it = std::max_element(a.begin(), a.end());
            const auto jt = std::min_element(b.begin(), b.end());
            if (*it > *jt)
                std::swap(*it, *jt);
        }
    }

    integer s = 0;
    for (const unsigned x : a)
        s += x;

    answer(s);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b, k);
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
