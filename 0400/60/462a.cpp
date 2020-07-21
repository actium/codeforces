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

void solve(const std::vector<std::string>& b)
{
    const size_t n = b.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            unsigned k = 0;
            if (j > 0 && b[i][j-1] == 'o')
                ++k;
            if (j+1 < n && b[i][j+1] == 'o')
                ++k;
            if (i > 0 && b[i-1][j] == 'o')
                ++k;
            if (i+1 < n && b[i+1][j] == 'o')
                ++k;

            if (k % 2 != 0)
                return answer(false);
        }
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}

