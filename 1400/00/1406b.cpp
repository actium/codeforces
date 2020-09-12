#include <algorithm>
#include <iostream>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    if (a.back() == 0)
        return answer(0);

    if (a.back() < 0) {
        integer p = 1;
        for (size_t i = 0; i < 5; ++i)
            p *= a[n-1-i];

        return answer(p);
    }

    size_t i = 0, j = n-1;
    integer p = a[j--];
    for (unsigned k = 0; k < 2; ++k) {
        const integer lp = a[i] * a[i+1];
        const integer rp = a[j] * a[j-1];
        if (lp > rp) {
            p *= lp;
            i += 2;
        } else {
            p *= rp;
            j -= 2;
        }
    }
    answer(p);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

