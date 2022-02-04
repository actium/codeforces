#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using piece_t = std::vector<std::string>;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<piece_t>& p)
{
    const size_t n = p[0].size();

    unsigned q[4] = {};
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k)
                q[i] += (p[i][j][k] != ((j + k) % 2 ^ '0'));
        }
    }

    unsigned s[4] = { 0, 1, 2, 3 }, z = n * n, k = ~0u;
    do {
        k = std::min(k, q[s[0]] + (z - q[s[1]]) + (z - q[s[2]]) + q[s[3]]);
        k = std::min(k, (z - q[s[0]]) + q[s[1]] + q[s[2]] + (z - q[s[3]]));
    } while (std::next_permutation(std::begin(s), std::end(s)));

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<piece_t> p(4, piece_t(n));
    std::cin >> p;

    solve(p);

    return 0;
}
