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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    if (a.front() == a.back())
        return answer(n / 2);

    integer x = (n + 1) / 2;
    while (x > 0 && a[x-1] == a[x])
        --x;

    integer y = (n + 1) / 2 + 1;
    while (y < n && a[y-1] == a[y])
        ++y;

    answer(std::max(x * (n - x), y * (n - y)));
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
