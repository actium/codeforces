#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    for (const unsigned x : v)
        std::cout << x;

    std::cout << '\n';
}

void solve(size_t n, const std::vector<unsigned>& a)
{
    const size_t m = a.size();

    std::vector<unsigned> f(n), v(m);
    for (size_t i = 0, k = 0; i < m; ++i) {
        const size_t x = a[i] - 1;
        if (f[x]++ == 0 && ++k == n) {
            for (unsigned& x : f) {
                if (--x == 0)
                    --k;
            }
            v[i] = 1;
        } else {
            v[i] = 0;
        }
    }

    answer(v);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(n, a);

    return 0;
}

