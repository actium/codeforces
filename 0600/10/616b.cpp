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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& c)
{
    const size_t n = c.size();

    unsigned x = 0;
    for (size_t i = 0; i < n; ++i) {
        const unsigned d = *std::min_element(c[i].cbegin(), c[i].cend());
        x = std::max(x, d);
    }

    answer(x);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> c(n, std::vector<unsigned>(m));
    std::cin >> c;

    solve(c);

    return 0;
}

