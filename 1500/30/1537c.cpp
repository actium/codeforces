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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& h)
{
    const size_t n = h.size();

    std::sort(h.begin(), h.end());

    unsigned d = h.back() - h.front(), k = 0;
    for (size_t i = 1; i < n; ++i) {
        if (h[i] - h[i-1] < d) {
            d = h[i] - h[i-1];
            k = i;
        }
    }

    std::rotate(h.begin(), h.begin() + k, h.end());

    answer(h);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
