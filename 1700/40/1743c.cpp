#include <iostream>
#include <string>
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

void solve(const std::vector<unsigned>& a, const std::string& m)
{
    const size_t n = a.size();

    unsigned t = 0, s = 0, x = 0;
    for (size_t i = 0; i < n; ++i) {
        if (m[i] == '0') {
            t += s - x;
            s = 0;
            x = ~0u;
        }
        s += a[i];
        x = std::min(x, a[i]);
    }

    answer(t + s - x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
