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

void solve(std::vector<unsigned>& a, unsigned x)
{
    std::sort(a.begin(), a.end());

    integer s = 0;
    for (const unsigned e : a)
        s += e;

    integer k = 0;
    for (unsigned d = 0; !a.empty(); ) {
        if (s > x) {
            s -= a.back() + d;
            a.pop_back();
        } else {
            const unsigned q = (x - s) / a.size() + 1;
            k += q * a.size();
            s += q * a.size();
            d += q;
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
