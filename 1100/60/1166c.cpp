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

void solve(std::vector<int>& a)
{
    std::transform(a.begin(), a.end(), a.begin(), abs);
    std::sort(a.begin(), a.end());

    integer k = 0;
    for (auto it = a.begin(); it != a.end(); ++it)
        k += std::upper_bound(it + 1, a.end(), *it * 2) - it - 1;

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
