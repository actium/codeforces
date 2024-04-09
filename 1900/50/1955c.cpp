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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, integer k)
{
    const size_t n = a.size();

    size_t i = 0, j = a.size() - 1;
    while (i < j && k > 1) {
        const unsigned d = std::min<integer>({ a[i], a[j], k / 2 });
        a[i] -= d;
        a[j] -= d;
        k -= 2 * d;

        i += (a[i] == 0);
        j -= (a[j] == 0);
    }
    a[i] -= std::min<integer>(a[i], k);

    answer(std::count(a.begin(), a.end(), 0));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer k;
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
