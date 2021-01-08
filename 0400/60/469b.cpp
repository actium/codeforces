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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

using segment_t = std::pair<unsigned, unsigned>;

void solve(const std::vector<segment_t>& a, const std::vector<segment_t>& b, unsigned l, unsigned r)
{
    const auto check = [&](unsigned t) {
        for (const auto& x : a) {
            for (const auto& y : b) {
                if (x.first <= y.second + t && x.second >= y.first + t)
                    return true;
            }
        }
        return false;
    };

    unsigned k = 0;
    for (unsigned t = l; t <= r; ++t)
        k += check(t);

    answer(k);
}

int main()
{
    size_t p, q;
    std::cin >> p >> q;

    unsigned l, r;
    std::cin >> l >> r;

    std::vector<segment_t> a(p), b(q);
    std::cin >> a >> b;

    solve(a, b, l ,r);

    return 0;
}

