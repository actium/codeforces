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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<std::string>& b)
{
    const size_t n = a.size();

    for (size_t i = 0; i < n; ++i) {
        for (const char c : b[i]) {
            if (c == 'D') {
                a[i] = (a[i] + 1) % 10;
            } else {
                a[i] = (a[i] + 9) % 10;
            }
        }
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::string> b(n);
    for (size_t i = 0; i < n; ++i) {
        size_t m;
        std::cin >> m >> b[i];
    }

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
