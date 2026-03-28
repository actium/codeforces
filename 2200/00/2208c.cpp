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

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& t)
{
    double v = 0;
    for (auto it = t.rbegin(); it != t.rend(); ++it) {
        const auto [c, p] = *it;
        if (100 * c > p * v) {
            v -= p * v / 100;
            v += c;
        }
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> t(n);
    std::cin >> t;

    solve(t);
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
