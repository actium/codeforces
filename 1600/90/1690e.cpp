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

void solve(std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    integer s = 0;
    for (unsigned& x : a) {
        s += x / k;
        x %= k;
    }

    std::sort(a.begin(), a.end());

    for (int i = 0, j = n - 1; i < j; ++i) {
        if (a[i] + a[j] >= k) {
            ++s;
            --j;
        }
    }

    answer(s);
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
