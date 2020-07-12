#include <iostream>
#include <numeric>
#include <vector>

#include <climits>

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

void solve(const std::vector<std::vector<unsigned>>& m)
{
    const size_t n = m.size();

    unsigned min = INT_MAX;
    for (const auto& x : m) {
        const unsigned k = x.size();
        min = std::min(min, k * 15 + std::accumulate(x.cbegin(), x.cend(), 0u) * 5);
    }

    answer(min);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> k(n);
    std::cin >> k;

    std::vector<std::vector<unsigned>> m(n);
    for (size_t i = 0; i < n; ++i) {
        m[i].resize(k[i]);
        std::cin >> m[i];
    }

    solve(m);

    return 0;
}

