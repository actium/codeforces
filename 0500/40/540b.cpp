#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(size_t n, const std::vector<unsigned>& a, unsigned p, unsigned x, unsigned y)
{
    const size_t k = a.size(), m = n - k;

    unsigned c = 0, s = 0;
    for (const unsigned v : a) {
        c += (v >= y);
        s += v;
    }

    std::vector<unsigned> b;
    for (size_t i = 0; i < m; ++i) {
        if (2 * c < n) {
            b.push_back(y);
            ++c;
        } else {
            b.push_back(1);
        }
        s += b.back();
    }

    s > x || 2 * c < n ? no_answer() : answer(b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    unsigned p, x, y;
    std::cin >> p >> x >> y;

    std::vector<unsigned> a(k);
    std::cin >> a;

    solve(n, a, p, x, y);

    return 0;
}
