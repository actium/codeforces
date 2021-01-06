#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> f(1000000);
    for (const unsigned x : a)
        ++f[x-1];

    unsigned long long s = 0;
    for (const unsigned x : a)
        s += x;

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        const auto r = s - a[i];
        if (r % 2 == 1)
            continue;

        const auto q = r / 2;
        if (q > 1000000)
            continue;

        const unsigned k = f[q-1] - (q == a[i]);
        if (k > 0)
            p.push_back(i);
    }

    answer(p);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

