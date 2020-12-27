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

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::vector<unsigned> f(k);
    for (const unsigned x : a)
        ++f[x-1];

    unsigned c = 0;
    while (f.back() < n) {
        for (size_t i = 1; i < k; ++i) {
            if (f[k-i-1] > 0)
                --f[k-i-1], ++f[k-i];
        }

        ++c;
    }

    answer(c);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

