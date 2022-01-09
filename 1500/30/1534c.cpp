#include <iostream>
#include <vector>

constexpr unsigned M = 1000000007;

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

void solve(const std::vector<unsigned>& p1, const std::vector<unsigned>& p2)
{
    const size_t n = p1.size();

    std::vector<unsigned> t(1+n);
    for (size_t i = 0; i < n; ++i)
        t[p1[i]] = p2[i];

    unsigned k = 0;
    std::vector<bool> v(1+n);
    for (const unsigned r : p1) {
        if (v[r])
            continue;

        unsigned x = r;
        do {
            v[x] = true;
            x = t[x];
        } while (x != r);

        ++k;
    }

    unsigned r = 1;
    for (unsigned long long b = 2; k != 0; k /= 2) {
        if (k & 1)
            r = r * b % M;

        b = b * b % M;
    }

    answer(r);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p1(n), p2(n);
    std::cin >> p1 >> p2;

    solve(p1, p2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
