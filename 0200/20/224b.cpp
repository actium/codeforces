#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << -1 << ' ' << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::map<unsigned, unsigned> f;
    size_t i = 0;
    while (i < n && f.size() < k)
        ++f[a[i++]];

    if (f.size() < k)
        return no_answer();

    size_t j = 0;
    while (f[a[j]] > 1)
        --f[a[j++]];

    answer(j+1, i);
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
