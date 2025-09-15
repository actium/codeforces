#include <algorithm>
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

void solve(std::vector<std::pair<unsigned, unsigned>>& r, unsigned m)
{
    std::sort(r.begin(), r.end());

    unsigned t = 0, x = 0, k = 0;
    for (const auto& [a, b] : r) {
        const unsigned dt = a - t, dx = b - x;
        if (dt % 2 == dx % 2)
            k += dt;
        else
            k += dt - 1;

        t = a;
        x = b;
    }

    answer(k + m - t);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> r(n);
    std::cin >> r;

    solve(r, m);
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
