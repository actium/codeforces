#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned n, unsigned m, unsigned k)
{
    const auto entrance = [=](unsigned x) {
        return (x - 1) / (m * k);
    };

    const auto floor = [=](unsigned x) {
        return (x - 1) % (m * k) / k;
    };

    const auto d = [](unsigned df) {
        return df > 2 ? 10 + df : df * 5;
    };

    unsigned ea = entrance(a), eb = entrance(b);
    if (ea > eb)
        std::swap(ea, eb);

    unsigned fa = floor(a), fb = floor(b);
    if (fa > fb)
        std::swap(fa, fb);

    if (ea == eb)
        return answer(d(fb - fa));

    answer(std::min(eb - ea, ea + n - eb) * 15 + d(fa) + d(fb));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m, k;
    std::cin >> n >> m >> k;

    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b, n, m, k);

    return 0;
}
