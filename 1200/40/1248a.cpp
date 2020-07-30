#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& p, const std::vector<unsigned>& q)
{
    unsigned long long fp[2] = {};
    for (const unsigned x : p)
        ++fp[x % 2];

    unsigned long long fq[2] = {};
    for (const unsigned x : q)
        ++fq[x % 2];

    answer(fp[0] * fq[0] + fp[1] * fq[1]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> q(m);
    std::cin >> q;

    solve(p, q);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

