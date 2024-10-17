#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size();

    integer s = n * (n + 1ull) / 2;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] != a[i-1])
            s += 1ull * i * (n - i);
    }

    for (const auto& [x, v] : r) {
        if (x > 1)
            s += 1ull * ((a[x-2] != v) - (a[x-2] != a[x-1])) * (x - 1) * (n - x + 1);

        if (x < n)
            s += 1ull * ((v != a[x]) - (a[x-1] != a[x])) * x * (n - x);

        a[x-1] = v;

        answer(s);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(a, r);

    return 0;
}
