#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void solve(unsigned w, unsigned h, const std::vector<std::vector<unsigned>>& p)
{
    const auto area = [](const std::vector<unsigned>& p, unsigned h) {
        return integer(p.back() - p.front()) * h;
    };

    answer(std::max({ area(p[0], h), area(p[1], h), area(p[2], w), area(p[3], w) }));
}

void test_case()
{
    unsigned w, h;
    std::cin >> w >> h;

    std::vector<std::vector<unsigned>> p(4);
    for (auto& v : p) {
        size_t k;
        std::cin >> k;

        v.resize(k);
        std::cin >> v;
    }

    solve(w, h, p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
