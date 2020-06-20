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

void solve(std::vector<unsigned>& h, size_t a, size_t b)
{
    std::sort(h.begin(), h.end());

    answer(h[b] - h[b-1]);
}

int main()
{
    size_t n, a, b;
    std::cin >> n >> a >> b;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h, a, b);

    return 0;
}

