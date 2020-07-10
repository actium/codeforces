#include <algorithm>
#include <iostream>
#include <numeric>
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

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& q)
{
    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    const unsigned long long sum = std::accumulate(std::begin(a), std::end(a), 0ull);
    std::for_each(std::begin(q), std::end(q), [&](unsigned x) { answer(sum - a[x-1]); });
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> q(m);
    std::cin >> q;

    solve(a, q);

    return 0;
}

