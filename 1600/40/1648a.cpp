#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

struct Node {
    size_t i = 0;
    integer d = 0;
    unsigned k = 0;
};

void solve(const std::vector<std::vector<unsigned>>& c)
{
    const size_t n = c.size(), m = c[0].size();

    integer s = 0;

    std::vector<Node> rs(100000);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            Node& x = rs[c[i][j]-1];

            if (i != x.i) {
                x.d += integer(i - x.i) * x.k;
                x.i = i;
            }

            s += x.d;
            ++x.k;
        }
    }

    std::vector<Node> cs(100000);
    for (size_t j = 0; j < m; ++j) {
        for (size_t i = 0; i < n; ++i) {
            Node& x = cs[c[i][j]-1];

            if (j != x.i) {
                x.d += integer(j - x.i) * x.k;
                x.i = j;
            }

            s += x.d;
            ++x.k;
        }
    }

    answer(s);
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
