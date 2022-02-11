#include <algorithm>
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

void solve(std::vector<unsigned>& p, const std::vector<std::vector<unsigned>>& a)
{
    unsigned t = 0;
    for (const std::vector<unsigned>& b : a) {
        for (const unsigned x : b) {
            auto it = std::find(p.begin(), p.end(), x);
            t += std::distance(p.begin(), it) + 1;

            for ( ; it != p.begin(); --it)
                std::swap(*it, *std::prev(it));
        }
    }

    answer(t);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> p(k);
    std::cin >> p;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(p, a);

    return 0;
}
