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
    std::cout << x;
}

void solve(std::vector<int>& x)
{
    const size_t n = x.size();

    std::sort(x.begin(), x.end());

    answer(x[(n-1)/2]);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> x(n);
    std::cin >> x;

    solve(x);

    return 0;
}
