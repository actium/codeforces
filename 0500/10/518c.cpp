#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& b, size_t k)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[a[i]-1] = i;

    integer q = 0;
    for (const unsigned x : b) {
        q += p[x-1] / k + 1;

        if (p[x-1] != 0) {
            const unsigned y = a[p[x-1]-1];
            std::swap(a[p[x-1]], a[p[y-1]]);
            std::swap(p[x-1], p[y-1]);
        }
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b, k);

    return 0;
}
