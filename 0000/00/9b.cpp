#include <iostream>
#include <vector>

#include <cmath>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << 1+v << '\n';
}

void solve(const std::vector<unsigned>& s, unsigned vb, unsigned vs, int x, int y)
{
    const size_t n = s.size();

    const auto d = [&](size_t i) {
        return hypot(abs(s[i] - x), abs(y));
    };

    size_t b = 1;
    for (size_t i = 2; i < n; ++i) {
        const double db = d(b), dc = d(i);

        const double tb = s[b] * vs + db * vb, tc = s[i] * vs + dc * vb;
        if (tc < tb || (tc == tb && dc < db))   // warning: operator ==(double, double) used
            b = i;
    }

    answer(b);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned vb, vs;
    std::cin >> vb >> vs;

    std::vector<unsigned> s(n);
    std::cin >> s;

    int x, y;
    std::cin >> x >> y;

    solve(s, vb, vs, x, y);

    return 0;
}

