#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(const std::vector<integer>& x, unsigned y)
{
    const char* separator = "";
    for (const integer a : x) {
        std::cout << separator << a;
        separator = " ";
    }
    std::cout << '\n';

    std::cout << y << '\n';
}

void solve(const std::vector<unsigned>& p, const std::vector<unsigned>& c)
{
    std::vector<integer> k(5);
    unsigned s = 0;
    for (const unsigned x : p) {
        s += x;

        for (size_t i = 4; ~i; --i) {
            k[i] += s / c[i];
            s %= c[i];
        }
    }

    answer(k, s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    std::vector<unsigned> c(5);
    std::cin >> c;

    solve(p, c);

    return 0;
}

