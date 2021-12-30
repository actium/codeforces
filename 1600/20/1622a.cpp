#include <algorithm>
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

void solve(std::vector<unsigned>& l)
{
    const auto next = [](size_t x) {
        return (x + 1) % 3;
    };

    for (size_t i = 0; i < 3; ++i) {
        if (l[i] == l[next(i)] && l[next(next(i))] % 2 == 0)
            return answer(true);
    }

    std::sort(l.begin(), l.end());

    answer(l[0] + l[1] == l[2]);
}

void test_case()
{
    std::vector<unsigned> l(3);
    std::cin >> l;

    solve(l);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
