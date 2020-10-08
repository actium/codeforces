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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const auto g = [k](unsigned x) {
        bool p[10] = {};
        do {
            p[x % 10] = true;
            x /= 10;
        } while (x != 0);

        return std::count(p + 0, p + k + 1, true) == k + 1;
    };

    unsigned c = 0;
    for (const unsigned x : a)
        c += g(x);

    answer(c);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

