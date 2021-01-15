#include <iostream>
#include <string>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(size_t n, const std::string& a, const std::string& b)
{
    const size_t m = a.length(), k = b.length(), u = m * k;

    const auto count = [&](size_t c) {
        constexpr char x[4] = { 'R', 'S', 'P', 'R' };

        std::pair<unsigned, unsigned> f = { 0, 0 };
        for (size_t i = 0; i < c; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                if (a[i%m] == x[j] && b[i%k] == x[j+1])
                    ++f.second;

                if (b[i%k] == x[j] && a[i%m] == x[j+1])
                    ++f.first;
            }
        }
        return f;
    };

    auto f = count(n % u);
    if (n >= u) {
        const auto p = count(u);
        f.first += n / u * p.first;
        f.second += n / u * p.second;
    }

    answer(f.first, f.second);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

    solve(n, a, b);

    return 0;
}

