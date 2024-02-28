#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool check(std::vector<std::vector<unsigned>> a, size_t p, size_t q)
{
    const size_t n = a.size(), m = a[0].size();

    for (size_t i = 0; i < n; ++i)
        std::swap(a[i][p], a[i][q]);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0, k = 0; j < m; ++j) {
            if (a[i][j] != 1 + j && ++k == 3)
                return false;
        }
    }
    return true;
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t m = a[0].size();

    for (size_t i = 1; i < m; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (check(a, j, i))
                return answer(true);
        }
    }

    answer(check(a, 0, 0));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a);

    return 0;
}
