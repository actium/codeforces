#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<size_t>& a, size_t s)
{
    size_t sum = 0, max = 0;
    for (const size_t x : a) {
        sum += x;
        max = std::max(max, x);
    }

    answer(sum <= s + max);
}

int main()
{
    size_t n, s;
    std::cin >> n >> s;

    std::vector<size_t> a(n);
    std::cin >> a;

    solve(a, s);

    return 0;
}

