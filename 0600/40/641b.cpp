#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    unsigned t;
    unsigned r;
    unsigned c;
    int x;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    input >> v.t;
    switch (v.t) {
        case 1:
            input >> v.r;
            break;
        case 2:
            input >> v.c;
            break;
        case 3:
            input >> v.r >> v.c >> v.x;
            break;
    }
    return input;
}

void answer(const std::vector<std::vector<int>>& v)
{
    for (const std::vector<int>& r : v) {
        const char* separator = "";
        for (const int x : r) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(size_t n, size_t m, const std::vector<Query>& q)
{
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (auto it = q.rbegin(); it != q.rend(); ++it) {
        switch (it->t) {
            case 1:
                {
                    const int x = a[it->r-1][m-1];
                    for (size_t j = m-1; j > 0; --j)
                        a[it->r-1][j] = a[it->r-1][j-1];

                    a[it->r-1][0] = x;
                }
                break;
            case 2:
                {
                    const int x = a[n-1][it->c-1];
                    for (size_t i = n-1; i > 0; --i)
                        a[i][it->c-1] = a[i-1][it->c-1];

                    a[0][it->c-1] = x;
                }
                break;
            case 3:
                a[it->r-1][it->c-1] = it->x;
                break;
        }
    }

    answer(a);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<Query> q(k);
    std::cin >> q;

    solve(n, m, q);

    return 0;
}
