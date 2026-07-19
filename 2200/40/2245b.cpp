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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<int>& a, int c)
{
    std::sort(a.begin(), a.end());

    integer s = 0;
    for (int i = 0, j = a.size() - 1; i <= j; ++i, --j) {
        if (i < j && a[i] > c)
            s += a[i] - c;

        s += a[j] - c;
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    int c;
    std::cin >> c;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, c);
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
