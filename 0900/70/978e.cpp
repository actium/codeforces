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

void solve(const std::vector<int>& a, unsigned w)
{
    long long x = 0, lx = 0, gx = 0;
    for (const int d : a) {
        x += d;

        lx = std::min(lx, x);
        gx = std::max(gx, x);
    }

    answer(std::max(w - (gx - lx) + 1, 0ll));
}

int main()
{
    unsigned n, w;
    std::cin >> n >> w;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, w);

    return 0;
}
