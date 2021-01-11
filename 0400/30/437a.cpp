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

void answer(char v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& c)
{
    unsigned d[4] = {};
    for (size_t i = 0; i < 4; ++i)
        d[i] = c[i].length() - 2;

    std::vector<size_t> b;
    for (size_t i = 0; i < 4; ++i) {
        unsigned x = ~0u, y = 0;
        for (size_t j = 0; j < 4; ++j) {
            if (j != i) {
                x = std::min(x, d[j]);
                y = std::max(y, d[j]);
            }
        }

        if (2 * d[i] <= x || 2 * y <= d[i])
            b.push_back(i);
    }

    answer(b.size() == 1 ? 'A' + b.front() : 'C');
}

int main()
{
    std::vector<std::string> c(4);
    std::cin >> c;

    solve(c);

    return 0;
}

