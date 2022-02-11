#include <iostream>
#include <string>
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
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::string>& b)
{
    const size_t n = b.size(), m = b[0].length();

    std::vector<unsigned> q(m);
    for (size_t j = 0; j < m; ++j) {
        for (size_t i = 1; i < n; ++i) {
            q[j] += (i <= j && b[i][j-i] == 'R');
            q[j] += (j+i < m && b[i][j+i] == 'L');
            q[j] += (i+i < n && b[i+i][j] == 'U');
        }
    }

    answer(q);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}
