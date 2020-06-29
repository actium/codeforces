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
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a, size_t x)
{
    size_t evens = 0, odds = 0;
    for (const size_t n : a) {
        if (n % 2 == 0)
            ++evens;
        else
            ++odds;
    }

    if (odds == 0)
        return answer(false);

    --odds, --x;

    if (evens >= x)
        return answer(true);

    if (x % 2 == 0) {
        evens -= evens % 2;
        x -= evens;
        return answer(odds >= x);
    }

    if (evens % 2 == 1) {
        x -= evens;
        return answer(odds >= x);
    }

    if (evens == 0)
        return answer(false);

    x -= (evens - 1);
    answer(odds >= x);
}

void test_case()
{
    size_t n, x;
    std::cin >> n >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

