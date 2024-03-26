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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& s, unsigned x)
{
    unsigned u = 0, d = 0;
    for (const std::pair<unsigned, unsigned>& p : s) {
        u = std::max(u, p.first);

        if (p.first > p.second)
            d = std::max(d, p.first - p.second);
    }

    if (u >= x)
        return answer(1);

    if (d == 0)
        return no_answer();

    answer((x - u + d - 1) / d + 1);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s, x);
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
