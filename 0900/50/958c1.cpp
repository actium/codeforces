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

void solve(const std::vector<unsigned>& a, unsigned p)
{
    const size_t n = a.size();

    std::vector<unsigned long long> ps(1+n);
    for (size_t i = 0; i < n; ++i)
        ps[1+i] += ps[i] + a[i];

    unsigned s = 0;
    for (size_t i = 0; i < n; ++i)
        s = std::max<unsigned>(s, ps[i] % p + (ps.back() - ps[i]) % p);

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned p;
    std::cin >> p;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, p);

    return 0;
}

