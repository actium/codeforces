#include <iostream>
#include <vector>

constexpr size_t K = 500000;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned x)
{
    std::vector<unsigned> f(1 + x);
    for (const unsigned v : a) {
        if (v < x)
            ++f[v];
    }

    for (unsigned i = 2; i <= x; ++i) {
        if (f[i-1] % i != 0)
            return answer(false);

        f[i] += f[i-1] / i;
    }

    answer(true);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);

    return 0;
}
