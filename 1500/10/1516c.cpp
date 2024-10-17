#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned s = 0;
    for (const unsigned x : a)
        s += x;

    if (s % 2 == 1)
        return answer({});

    std::vector<bool> dp(1+s);
    dp[0] = true;
    for (const unsigned b : a) {
        for (unsigned x = s; x >= b; --x)
            dp[x] = dp[x] || dp[x-b];
    }

    if (!dp[s/2])
        return answer({});

    size_t x = 0;
    for (size_t i = 1; i < n; ++i) {
        if (__builtin_ctz(a[i]) < __builtin_ctz(a[x]))
            x = i;
    }

    answer({ x });
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
