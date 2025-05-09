#include <iostream>

using integer = unsigned long long;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

integer resolve(std::pair<unsigned, unsigned> p, integer b, unsigned w)
{
    if (w == 1)
        return b;

    const integer k = integer(w / 2) * (w / 2);

    if (p.first <= w / 2) {
        if (p.second <= w / 2) {
            // do nothing
        } else {
            p.second -= w / 2;
            b += 3 * k;
        }
    } else {
        if (p.second <= w / 2) {
            p.first -= w / 2;
            b += 2 * k;
        } else {
            p.first -= w / 2;
            p.second -= w / 2;
            b += k;
        }
    }
    return resolve(p, b, w / 2);
}

std::pair<unsigned, unsigned> resolve(integer d, integer b, unsigned w)
{
    if (w == 1)
        return { 1, 1 };

    const integer k = integer(w / 2) * (w / 2);

    if (d >= b + 3 * k) {
        std::pair<unsigned, unsigned> p = resolve(d, b + 3 * k, w / 2);
        p.second += w / 2;
        return p;
    }
    if (d >= b + 2 * k) {
        std::pair<unsigned, unsigned> p = resolve(d, b + 2 * k, w / 2);
        p.first += w / 2;
        return p;
    }
    if (d >= b + k) {
        std::pair<unsigned, unsigned> p = resolve(d, b + k, w / 2);
        p.first += w / 2;
        p.second += w / 2;
        return p;
    }
    return resolve(d, b, w / 2);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    size_t q;
    std::cin >> q;

    for (size_t i = 0; i < q; ++i) {
        std::string t;
        std::cin >> t;

        if (t[0] == '<') {
            integer d;
            std::cin >> d;

            const std::pair<unsigned, unsigned> p = resolve(d, 1, 1 << n);
            std::cout << p.first << ' ' << p.second << '\n';
        } else {
            std::pair<unsigned, unsigned> p;
            std::cin >> p;

            const integer d = resolve(p, 1, 1 << n);
            std::cout << d << '\n';
        }
    }
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
