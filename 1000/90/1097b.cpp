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

bool solve(const std::vector<unsigned>& a, int x, size_t i)
{
    if (i == a.size())
        return x % 360 == 0;

    return solve(a, x + a[i], i+1) || solve(a, x - a[i], i+1);
}

void solve(const std::vector<unsigned>& a)
{
    answer(solve(a, 0, 0));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

