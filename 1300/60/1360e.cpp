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

void solve(const std::vector<std::string>& b)
{
    const size_t n = b.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (b[i][j] == '1') {
                if (i == n-1 || j == n-1)
                    continue;

                if (b[i+1][j] == '0' && b[i][j+1] == '0')
                    return answer(false);
            }
        }
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

