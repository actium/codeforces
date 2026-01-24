#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& a, unsigned h, unsigned w)
{
    unsigned cv = 0, ch = 0;
    for (const unsigned x : a) {
        cv += (x <= h);
        ch += (x <= w);
    }

    answer(h < w ? std::min(cv, ch / 2) : std::min(cv / 2, ch));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned h, w;
    std::cin >> h >> w;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, h, w);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
