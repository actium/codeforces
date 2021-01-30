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
};

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::pair<int, int>>& s, size_t k)
{
    const auto f = [&](long long x) {
        long long c = 0;
        for (const auto [l, r] : s) {
            if (x > l)
                c += std::min(x, r + 1ll) - l;
        }
        return c > k;
    };

    answer(search<long long>(-2000000000, 2000000001, f));
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> s(n);
    std::cin >> s;

    solve(s, k);

    return 0;
}

