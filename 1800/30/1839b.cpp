#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(std::vector<std::pair<unsigned, unsigned>>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), [](const std::pair<unsigned, unsigned>& x, const std::pair<unsigned, unsigned>& y) {
        if (x.first != y.first)
            return x.first < y.first;

        return x.second > y.second;
    });

    integer s = 0;
    for (size_t i = 0, j; i < n; i = j) {
        for (j = i; j < n && a[j].first == a[i].first; ++j) {
            if (j - i < a[i].first)
                s += a[j].second;
        }
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> a(n);
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
