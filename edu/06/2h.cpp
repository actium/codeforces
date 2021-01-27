#include <array>
#include <iostream>
#include <string>

using count_t = unsigned long long;

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
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

void answer(count_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& r, const std::array<unsigned, 3>& n, const std::array<unsigned, 3>& p, count_t b)
{
    unsigned c[3] = {};
    for (const char x : r) {
        c[0] += (x == 'B');
        c[1] += (x == 'S');
        c[2] += (x == 'C');
    }

    const auto f = [&](count_t q) {
        count_t r = b;
        for (size_t i = 0; i < 3; ++i) {
            const count_t k = q * c[i];
            if (n[i] < k) {
                const count_t d = (k - n[i]) * p[i];
                if (d > r)
                    return true;

                r -= d;
            }
        }
        return false;
    };

    answer(search<count_t>(0, b + 101, f));
}

int main()
{
    std::string r;
    std::cin >> r;

    std::array<unsigned, 3> n, p;
    std::cin >> n >> p;

    count_t b;
    std::cin >> b;

    solve(r, n, p, b);

    return 0;
}

