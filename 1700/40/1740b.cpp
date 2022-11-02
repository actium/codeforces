#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& s)
{
    for (std::pair<unsigned, unsigned>& r : s) {
        if (r.first < r.second)
            std::swap(r.first, r.second);
    }

    std::sort(s.begin(), s.end());

    integer p = s.back().first;
    for (const std::pair<unsigned, unsigned>& r : s) {
        p += 2 * r.second;
    }
    p += s.back().first;

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
