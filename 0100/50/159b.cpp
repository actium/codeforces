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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& p, const std::vector<std::pair<unsigned, unsigned>>& c)
{
    unsigned f[1000][1000] = {}, q[1000] = {};
    for (const auto& e : p) {
        ++f[e.first-1][e.second-1];
        ++q[e.second-1];
    }

    unsigned u = 0, v = 0;
    for (const auto& e : c) {
        if (q[e.second-1] > 0) {
            --q[e.second-1];
            ++u;
        }
        if (f[e.first-1][e.second-1] > 0) {
            --f[e.first-1][e.second-1];
            ++v;
        }
    }

    answer(u, v);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    std::vector<std::pair<unsigned, unsigned>> c(m);
    std::cin >> c;

    solve(p, c);

    return 0;
}

