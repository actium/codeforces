#include <iostream>
#include <vector>

using point_t = std::pair<unsigned, unsigned>;

std::istream& operator >>(std::istream& input, point_t& v)
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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<point_t>& p)
{
    unsigned d = 0;
    for (const point_t& x : p) {
        d = std::max(d, x.first + x.second);
    }

    answer(d);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<point_t> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}

