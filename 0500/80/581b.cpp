#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& h)
{
    const size_t n = h.size();

    std::vector<unsigned> d(n);
    for (unsigned x = 0, i = n; i-- > 0; x = std::max(x, h[i]))
        d[i] = (h[i] > x ? 0 : x + 1 - h[i]);

    answer(d);
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

