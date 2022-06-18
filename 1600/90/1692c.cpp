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

void answer(unsigned x, unsigned y)
{
    std::cout << 1+x << ' ' << 1+y << '\n';
}

void solve(const std::vector<std::string>& b)
{
    for (size_t i = 1; i < 7; ++i) {
        for (size_t j = 1; j < 7; ++j) {
            if (b[i][j] == '#' && b[i-1][j-1] == '#' && b[i-1][j+1] == '#')
                return answer(i, j);
        }
    }
}

void test_case()
{
    std::vector<std::string> b(8);
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
