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

void solve(const std::vector<unsigned>& k, std::vector<unsigned>& h)
{
    const size_t n = h.size();

    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            const unsigned dt = k[i] - k[j];
            if (dt < h[i]) {
                h[i] = std::max(h[i], h[j] + dt);
                h[j] = 0;
            }
        }
    }

    integer c = 0;
    for (const unsigned x : h)
        c += integer(1 + x) * x / 2;

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> k(n), h(n);
    std::cin >> k >> h;

    solve(k, h);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
