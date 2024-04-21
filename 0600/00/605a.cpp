#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<size_t> x(1 + n);
    for (size_t i = 0; i < n; ++i)
        x[p[i]] = i;

    unsigned k = 0;
    for (unsigned i = 1, j = 2; i <= n; i = j++) {
        while (j <= n && x[j] > x[j-1])
            ++j;

        k = std::max(k, j - i);
    }

    answer(n - k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
