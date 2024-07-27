#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned c)
{
    const size_t n = a.size();

    std::vector<unsigned> t(1+n);
    {
        std::pair<unsigned, unsigned> dp = { 0, c };
        for (size_t i = 0; i < n; ++i) {
            dp = {
                std::min(dp.first, dp.second) + a[i],
                std::min(dp.first + c, dp.second) + b[i]
            };

            t[i+1] = std::min(dp.first, dp.second);
        }
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned c;
    std::cin >> c;

    std::vector<unsigned> a(n-1), b(n-1);
    std::cin >> a >> b;

    solve(a, b, c);

    return 0;
}
