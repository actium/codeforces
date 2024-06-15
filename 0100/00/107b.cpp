#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, const std::vector<unsigned>& s, unsigned h)
{
    unsigned t = 0;
    for (const unsigned x : s)
        t += x;

    if (t < n)
        return no_answer();

    if (t - s[h-1] < n - 1)
        return answer(1);

    double p = 1;
    for (unsigned i = 1; i < n; ++i)
        p *= (t - s[h-1] - i + 1.0) / (t - i);

    answer(1 - p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m, h;
    std::cin >> n >> m >> h;

    std::vector<unsigned> s(m);
    std::cin >> s;

    solve(n, s, h);

    return 0;
}
