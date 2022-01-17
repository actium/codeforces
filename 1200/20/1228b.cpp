#include <iostream>
#include <vector>

constexpr unsigned M = 1000000007;

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

void solve(const std::vector<unsigned>& r, const std::vector<unsigned>& c)
{
    const size_t h = r.size(), w = c.size();

    std::vector<std::vector<unsigned>> b(h, std::vector<unsigned>(w, 2));

    const auto set = [&b](size_t i, size_t j, unsigned v) {
        if (b[i][j] != 2)
            return b[i][j] == v;

        b[i][j] = v;
        return true;
    };

    for (size_t i = 0; i < h; ++i) {
        for (size_t j = 0; j < r[i]; ++j) {
            if (!set(i, j, 1))
                return answer(0);
        }
        if (r[i] < w && !set(i, r[i], 0))
            return answer(0);
    }
    for (size_t j = 0; j < w; ++j) {
        for (size_t i = 0; i < c[j]; ++i) {
            if (!set(i, j, 1))
                return answer(0);
        }
        if (c[j] < h && !set(c[j], j, 0))
                return answer(0);
    }

    unsigned k = 1;
    for (size_t i = 0; i < h; ++i) {
        for (size_t j = 0; j < w; ++j) {
            if (b[i][j] == 2)
                k = k * 2 % M;
        }
    }

    answer(k);
}

int main()
{
    size_t h, w;
    std::cin >> h >> w;

    std::vector<unsigned> r(h), c(w);
    std::cin >> r >> c;

    solve(r, c);

    return 0;
}
