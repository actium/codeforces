#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned s)
{
    const size_t n = a.size();

    unsigned long long f[1+s] = { 1 };

    unsigned k = ~0u;
    for (size_t i = 0, j = 0; j < n; ++j) {
        for (unsigned x = s; x >= a[j]; --x)
            f[x] += f[x-a[j]];

        for ( ; f[s] > 0; ++i) {
            for (unsigned x = a[i]; x <= s; ++x)
                f[x] -= f[x-a[i]];

            k = std::min<unsigned>(k, j - i + 1);
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, s);

    return 0;
}

