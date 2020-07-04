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
    constexpr const char* s[2] = { "odd", "even" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a, size_t b)
{
    if (b % 2 == 0)
        return answer(a.back() % 2 == 0);

    size_t c = 0;
    for (const unsigned x : a)
        c += x % 2;

    answer(c % 2 == 0);
}

int main()
{
    size_t b, k;
    std::cin >> b >> k;

    std::vector<unsigned> a(k);
    std::cin >> a;

    solve(a, b);

    return 0;
}

