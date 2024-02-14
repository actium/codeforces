#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& a, unsigned x, unsigned y)
{
    integer k = 0;

    std::map<std::pair<unsigned, unsigned>, unsigned> f;
    for (const unsigned v : a) {
        const auto it = f.find(std::make_pair((x - v % x) % x, v % y));
        if (it != f.end())
            k += it->second;

        ++f[std::make_pair(v % x, v % y)];
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x, y;
    std::cin >> x >> y;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x, y);
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
