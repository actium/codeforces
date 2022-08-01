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

void solve(const std::vector<unsigned>& c)
{
    const size_t n = c.size();

    std::vector<std::vector<size_t>> p(n);
    for (size_t i = 0; i < n; ++i) {
        p[c[i]-1].push_back(i);
    }

    std::vector<unsigned> k(n);
    for (size_t i = 0; i < n; ++i) {
        size_t q = n;
        for (const size_t x : p[i]) {
            if (q == n || (x - q) % 2 == 1) {
                ++k[i];
                q = x;
            }
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
