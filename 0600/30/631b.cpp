#include <array>
#include <iostream>
#include <vector>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const auto& u : v) {
        const char* separator = "";
        for (const unsigned x : u) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(size_t n, size_t m, const std::vector<std::array<unsigned, 3>>& q)
{
    const size_t k = q.size();

    std::vector<int> r(n, -1), c(m, -1);
    for (size_t i = 0; i < k; ++i) {
        if (q[i][0] == 1)
            r[q[i][1]-1] = i;
        else
            c[q[i][1]-1] = i;
    }

    std::vector<std::vector<unsigned>> b(n, std::vector<unsigned>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            const int x = std::max(r[i], c[j]);
            if (x != -1)
                b[i][j] = q[x][2];
        }
    }

    answer(b);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::array<unsigned, 3>> q(k);
    std::cin >> q;

    solve(n, m, q);

    return 0;
}

