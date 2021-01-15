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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& f, size_t k)
{
    const size_t n = f.size();

    std::sort(f.begin(), f.end(), std::greater<unsigned>());

    unsigned t = 0;
    for (size_t i = 0; i < n; i += k)
        t += 2 * (f[i] - 1);

    answer(t);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> f(n);
    std::cin >> f;

    solve(f, k);

    return 0;
}

