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

void solve(const std::vector<unsigned>& a, unsigned u, unsigned v)
{
    const size_t n = a.size();

    unsigned x = ~0u;
    for (size_t i = 1; i < n; ++i) {
        const int j = a[i-1], k = a[i];
        switch (abs(j - k)) {
            case 0:
                x = std::min(x, v + u);
                x = std::min(x, v + v);
                break;

            case 1:
                x = std::min(x, u);
                x = std::min(x, v);
                break;

            default:
                x = 0;
        }
    }

    answer(x);
}

void test_case()
{
    unsigned n, u, v;
    std::cin >> n >> u >> v;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, u, v);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
