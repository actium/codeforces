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

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::string>& b)
{
    const auto check = [&b](char x) {
        for (size_t i = 0; i < 3; ++i) {
            unsigned h = 0, v = 0;
            for (size_t j = 0; j < 3; ++j) {
                h += (b[i][j] == x);
                v += (b[j][i] == x);
            }
            if (h == 3 || v == 3)
                return true;
        }

        unsigned d1 = 0, d2 = 0;
        for (size_t i = 0; i < 3; ++i) {
            d1 += (b[i][i] == x);
            d2 += (b[i][2-i] == x);
        }
        return d1 == 3 || d2 == 3;
    };

    for (const char* c : { "X", "O", "+" }) {
        if (check(*c))
            return answer(c);
    }

    answer("DRAW");
}

void test_case()
{
    std::vector<std::string> b(3);
    std::cin >> b;

    solve(b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
