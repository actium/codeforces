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

void answer(const std::vector<std::string>& v)
{
    for (const auto& x : v)
        std::cout << x << '\n';
}

void solve(std::vector<std::string>& b)
{
    const size_t n = b.size();

    const auto search = [&](size_t r, size_t c) {
        if (c == n)
            ++r, c = 0;

        while (b[r][c] != '*') {
            if (++c == n)
                ++r, c = 0;
        }

        return std::make_pair(r, c);
    };

    auto [r1, c1] = search(0, 0);
    auto [r2, c2] = search(r1, c1 + 1);

    if (r1 == r2)
        r2 = (r1 + 1) % n;

    if (c1 == c2)
        c2 = (c1 + 1) % n;

    b[r1][c1] = b[r1][c2] = b[r2][c1] = b[r2][c2] = '*';

    answer(b);
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
