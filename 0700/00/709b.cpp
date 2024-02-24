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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<int>& x, int a)
{
    const size_t n = x.size();
    if (n == 1)
        return answer(0);

    std::sort(x.begin(), x.end());

    const unsigned d1 = abs(x[n-2] - a) + x[n-2] - x[0];
    const unsigned d2 = abs(x[n-1] - a) + x[n-1] - x[1];
    const unsigned d3 = abs(a - x[1]) + x[n-1] - x[1];
    const unsigned d4 = abs(a - x[0]) + x[n-2] - x[0];

    answer(std::min({d1, d2, d3, d4}));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    int a;
    std::cin >> a;

    std::vector<int> x(n);
    std::cin >> x;

    solve(x, a);

    return 0;
}
