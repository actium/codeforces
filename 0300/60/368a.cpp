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

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, unsigned d, unsigned m)
{
    const size_t n = a.size();

    if (n <= m) {
        const unsigned s = std::accumulate(a.cbegin(), a.cend(), 0u);
        const unsigned p = (m - n) * d;
        answer(s - p);
    } else {
        std::sort(a.begin(), a.end());

        const unsigned s = std::accumulate(a.cbegin(), a.cbegin() + m, 0u);
        answer(s);
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned d;
    std::cin >> d;

    std::vector<unsigned> a(n);
    std::cin >> a;

    unsigned m;
    std::cin >> m;

    solve(a, d, m);

    return 0;
}

