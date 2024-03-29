#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    int s = 0;
    for (const int x : a)
        s += x;

    int d = (a[0] == -1 ? 0 : 4);
    for (size_t i = 1; i < n; ++i) {
        if (a[i-1] == -1 && a[i] == -1)
            return answer(s + 4);

        if (a[i] == -1)
            d = 0;
    }

    answer(s - d);
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
