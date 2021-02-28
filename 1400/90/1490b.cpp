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

void solve(const std::vector<unsigned>& a)
{
    const unsigned n = a.size() / 3;

    unsigned f[3] = {};
    for (const unsigned x : a)
        ++f[x % 3];

    unsigned k = 0;
    while (f[0] != n || f[1] != n || f[2] != n) {
        if (f[0] > n) {
            const unsigned c = f[0] - n;
            f[0] -= c, f[1] += c, k += c;
        }
        if (f[1] > n) {
            const unsigned c = f[1] - n;
            f[1] -= c, f[2] += c, k += c;
        }
        if (f[2] > n) {
            const unsigned c = f[2] - n;
            f[2] -= c, f[0] += c, k += c;
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

