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

void answer(size_t x, size_t y)
{
    std::cout << "YES" << '\n';
    std::cout << 1+x << ' ' << 1+y << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(std::vector<std::string>& b)
{
    const size_t n = b.size(), m = b[0].length();

    std::vector<unsigned> rq(n), cq(m);
    unsigned q = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (b[i][j] == '*') {
                ++rq[i];
                ++cq[j];
                ++q;
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            const unsigned k = rq[i] + cq[j] - (b[i][j] == '*');
            if (k == q)
                return answer(i, j);
        }
    }

    no_answer();
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}
