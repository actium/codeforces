#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::vector<size_t>>& v)
{
    std::cout << "YES" << '\n';

    for (const auto& r : v) {
        const char* separator = "";
        for (const unsigned x : r) {
            std::cout << separator << 1+x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<unsigned>& h)
{
    const size_t n = h.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = i;

    std::sort(x.begin(), x.end(), [&h](size_t a, size_t b) { return h[a] < h[b]; });

    std::vector<std::vector<size_t>> p = { x, x, x };
    for (size_t i = 1; i < 3; ++i) {
        for (size_t j = 1, c = 0; j < n && c < i; ++j) {
            if (h[p[i][j]] == h[p[i][j-1]]) {
                std::swap(p[i][j], p[i][j-1]);
                ++c;
            }
        }
    }

    if (p[0] == p[1] || p[0] == p[2] || p[1] == p[2])
        return no_answer();

    answer(p);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h);

    return 0;
}

