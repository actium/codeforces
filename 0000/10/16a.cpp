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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::string>& f, size_t m)
{
    const size_t n = f.size();

    for (size_t i = 0; i < n; ++i) {
        if (i > 0 && f[i][0] == f[i-1][0])
            return answer(false);

        if (i < n-1 && f[i][0] == f[i+1][0])
            return answer(false);

        for (size_t j = 1; j < m; ++j) {
            if (f[i][j] != f[i][j-1])
                return answer(false);
        }
    }

    answer(true);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> f(n);
    std::cin >> f;

    solve(f, m);

    return 0;
}

