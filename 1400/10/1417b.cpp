#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(const std::vector<unsigned>& a, unsigned t)
{
    std::map<unsigned, unsigned> f[2];

    const char* separator = "";
    for (const unsigned x : a) {
        unsigned c = 0;
        if (x <= t) {
            const unsigned d = t - x;
            if (f[0][d] > f[1][d])
                c = 1;

            ++f[c][x];
        }

        std::cout << separator << c;
        separator = " ";
    }
    std::cout << '\n';
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned t;
    std::cin >> t;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, t);
}

int main()
{
    size_t t = 1;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

