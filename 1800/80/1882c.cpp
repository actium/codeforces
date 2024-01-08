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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<size_t> p[2];
    for (size_t i = 0; i < n; ++i) {
        if (a[i] >= 0)
            p[i%2].push_back(i);
    }

    integer v = 0;
    while (!p[0].empty()) {
        while (!p[1].empty() && p[1].back() > p[0].back()) {
            v += a[p[1].back()];
            p[1].pop_back();
        }

        v += a[p[0].back()];
        p[0].pop_back();
    }

    while (!p[1].empty() && p[1].back() > 1) {
        v += a[p[1].back()];
        p[1].pop_back();
    }

    if (!p[1].empty() && -a[0] < a[1])
        v += a[0] + a[1];

    answer(v);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
