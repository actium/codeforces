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
    for (const std::string x : v)
        std::cout << x << '\n';
}

void solve(std::vector<std::string>& p)
{
    const size_t h = p.size(), w = p[0].length();

    std::vector<std::string> r(2 * w, std::string(2 * h, ' '));
    for (size_t i = 0; i < h; ++i) {
        for (size_t j = 0; j < w; ++j) {
            r[2*j+0][2*i+0] = p[i][j];
            r[2*j+0][2*i+1] = p[i][j];
            r[2*j+1][2*i+0] = p[i][j];
            r[2*j+1][2*i+1] = p[i][j];
        }
    }

    answer(r);
}

int main()
{
    size_t w, h;
    std::cin >> w >> h;

    std::vector<std::string> p(h);
    std::cin >> p;

    solve(p);

    return 0;
}

