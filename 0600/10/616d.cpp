#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x, size_t y)
{
    std::cout << 1+x << ' ' << 1+y << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    size_t l = 0, r = 0;
    {
        std::vector<unsigned> f(1000001);
        for (size_t i = 0, j = 0, c = 0; j < n; ++j) {
            c += (f[a[j]]++ == 0);

            while (c > k) {
                c -= (--f[a[i]] == 0);
                ++i;
            }

            if (j - i > r - l) {
                l = i;
                r = j;
            }
        }
    }

    answer(l, r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
