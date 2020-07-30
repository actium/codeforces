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

void solve(const std::vector<unsigned>& h)
{
    const size_t n = h.size();

    unsigned t = h[0];
    for (size_t i = 1; i < n; ++i)
        t += std::max(h[i-1], h[i]) - std::min(h[i-1], h[i]);

    answer(t + 2 * n - 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h);

    return 0;
}

