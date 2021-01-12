#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(std::vector<std::pair<unsigned, unsigned>>& p, size_t k)
{
    const auto compare = [](const std::pair<unsigned, unsigned>& a, const std::pair<unsigned, unsigned>& b) {
        const unsigned da = std::min(a.first * 2, a.second) - std::min(a.first, a.second);
        const unsigned db = std::min(b.first * 2, b.second) - std::min(b.first, b.second);
        return da > db;
    };
    std::sort(p.begin(), p.end(), compare);

    unsigned long long c = 0;
    for (const auto& x : p) {
        if (k > 0) {
            c += std::min(2 * x.first, x.second);
            --k;
        } else {
            c += std::min(x.first, x.second);
        }
    }

    answer(c);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p, k);

    return 0;
}

