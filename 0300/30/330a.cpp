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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& p, size_t c)
{
    const size_t r = p.size();

    size_t rc = 0;
    for (size_t i = 0; i < r; ++i) {
        for (size_t j = 0; j < c; ++j) {
            if (p[i][j] == 'S') {
                ++rc;
                break;
            }
        }
    }

    size_t cc = 0;
    for (size_t j = 0; j < c; ++j) {
        for (size_t i = 0; i < r; ++i) {
            if (p[i][j] == 'S') {
                ++cc;
                break;
            }
        }
    }

    answer(r * c - rc * cc);
}

int main()
{
    size_t r, c;
    std::cin >> r >> c;

    std::vector<std::string> p(r);
    std::cin >> p;

    solve(p, c);

    return 0;
}

