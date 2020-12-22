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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& w)
{
    const size_t n = w.size();

    std::vector<std::vector<unsigned>> f(n, std::vector<unsigned>(26));
    for (size_t i = 0; i < n; ++i) {
        for (const char c : w[i])
            ++f[i][c - 'a'];
    }

    unsigned b = 0;
    for (size_t i = 0; i < 26; ++i) {
        for (size_t j = 0; j < 26; ++j) {
            unsigned c = 0;
            for (size_t k = 0; k < n; ++k) {
                const size_t m = w[k].length();
                if (f[k][i] + (j != i ? f[k][j] : 0) == m)
                    c += m;
            }

            b = std::max(b, c);
        }
    }

    answer(b);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> w(n);
    std::cin >> w;

    solve(w);

    return 0;
}

