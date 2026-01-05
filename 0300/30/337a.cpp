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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::vector<size_t>& f, size_t n)
{
    std::sort(f.begin(), f.end());

    size_t min_delta = f[n-1] - f[0];
    for (size_t left = 1, right = n, m = f.size(); right < m; ++left, ++right)
        min_delta = std::min(min_delta, f[right] - f[left]);

    answer(min_delta);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<size_t> f(m);
    std::cin >> f;

    solve(f, n);

    return 0;
}

