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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    a.push_back(0);     // sentinel

    integer k = 0;
    for (size_t i = 1; i < n; i += 2) {
        if (a[i] >= a[i-1] + a[i+1])
            continue;

        if (a[i] < a[i-1]) {
            k += a[i-1] - a[i];
            a[i-1] = a[i];
        }

        k += a[i-1] + a[i+1] - a[i];
        a[i+1] -= a[i-1] + a[i+1] - a[i];
    }

    answer(k);
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
