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

void solve(std::vector<unsigned>& a, unsigned c, unsigned k)
{
    std::sort(a.begin(), a.end());

    integer p = c;
    for (const unsigned x : a) {
        if (p < x)
            break;

        const unsigned d = std::min<integer>(p - x, k);
        p += x + d;
        k -= d;
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned c, k;
    std::cin >> c >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, c, k);
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
