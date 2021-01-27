#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T, typename F>
T search(T lb, T ub, F&& f)
{
    for (auto k = ub - lb; k > 1; ) {
        const auto half = k / 2;
        if (!f(lb + half))
            lb += half;

        k -= half;
    }
    return lb;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<int>& a, int x)
{
    const auto p = search(a.cbegin(), a.cend(), [x](auto it) { return *it > x; });
    answer(*p == x);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<int> a(n);
    std::cin >> a;

    while (k-- > 0) {
        int x;
        std::cin >> x;

        solve(a, x);
    }

    return 0;
}

