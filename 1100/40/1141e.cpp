#include <iostream>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer h, const std::vector<int>& d)
{
    const size_t n = d.size();

    integer b = 0, c = 0;
    for (size_t i = 0; i < n; ++i) {
        b += d[i];

        if (h + b <= 0)
            return answer(i + 1);

        c = std::min(c, b);
    }

    if (b < 0) {
        const integer q = (h + c - b - 1) / -b;
        h += b * q;

        integer t = q * n;
        for (size_t i = 0; h > 0; ++i) {
            h += d[i];
            ++t;
        }
        return answer(t);
    }

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer h;
    std::cin >> h;

    size_t n;
    std::cin >> n;

    std::vector<int> d(n);
    std::cin >> d;

    solve(h, d);

    return 0;
}
