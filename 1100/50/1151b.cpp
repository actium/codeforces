#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << "TAK" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NIE" << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    unsigned x = 0;
    for (size_t i = 0; i < n; ++i)
        x ^= a[i][0];

    std::vector<unsigned> v(n, 1);
    for (size_t i = 0; i < n && x == 0; ++i) {
        for (size_t j = 1; j < m; ++j) {
            if (a[i][j] != a[i][0]) {
                x ^= a[i][0] ^ a[i][j];
                v[i] = j + 1;
                break;
            }
        }
    }

    x == 0 ? no_answer() : answer(v);
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
