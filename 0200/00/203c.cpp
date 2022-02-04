#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& c, unsigned d, unsigned a, unsigned b)
{
    const size_t n = c.size();

    const auto p = [a, b](const std::pair<unsigned, unsigned>& c) {
        return c.first * a + c.second * b;
    };

    std::vector<size_t> o(n);
    for (size_t i = 0; i < n; ++i)
        o[i] = i;

    std::sort(o.begin(), o.end(), [&](size_t x, size_t y) { return p(c[x]) < p(c[y]); });

    std::vector<size_t> s;
    for (const size_t i : o) {
        const unsigned q = p(c[i]);
        if (q <= d) {
            s.push_back(i);
            d -= q;
        }
    }

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned d;
    std::cin >> d;

    unsigned a, b;
    std::cin >> a >> b;

    std::vector<std::pair<unsigned, unsigned>> c(n);
    std::cin >> c;

    solve(c, d, a, b);

    return 0;
}
