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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& t, unsigned h, unsigned m)
{
    const unsigned ts = h * 60 + m;

    unsigned d = 24 * 60;
    for (const std::pair<unsigned, unsigned>& e : t) {
        unsigned x = e.first * 60 + e.second;
        if (x < ts)
            x += 24 * 60;

        d = std::min(d, x - ts);
    }

    answer(d / 60, d % 60);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned h, m;
    std::cin >> h >> m;

    std::vector<std::pair<unsigned, unsigned>> t(n);
    std::cin >> t;

    solve(t, h, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
