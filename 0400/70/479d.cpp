#include <algorithm>
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
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned l, unsigned x, unsigned y)
{
    const auto check = [&](unsigned p) {
        return std::binary_search(a.begin(), a.end(), p);
    };

    unsigned r[2] = { 1, 1 };
    for (const unsigned p : a) {
        if (check(p + x) || check(p - x))
            r[0] = 0;

        if (check(p + y) || check(p - y))
            r[1] = 0;
    }

    if (r[0] + r[1] == 0)
        return answer({});

    if (r[0] == 0)
        return answer({ y });
    if (r[1] == 0)
        return answer({ x });

    for (const unsigned p : a) {
        if (p + y <= l && check(p + y - x) || check(p + y + x))
            return answer({ p + y });

        if (p >= y && check(p - y + x) || check(p - y - x))
            return answer({ p - y });
    }

    answer({ x, y });
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned l, x, y;
    std::cin >> l >> x >> y;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, l, x, y);

    return 0;
}
