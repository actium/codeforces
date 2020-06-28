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

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(std::vector<int>& a, size_t m)
{
    std::sort(a.begin(), a.end());

    int sum = 0;
    for (size_t i = 0; i < m && a[i] < 0; ++i)
        sum -= a[i];

    answer(sum);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, m);

    return 0;
}

