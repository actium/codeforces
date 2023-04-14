#include <algorithm>
#include <iostream>
#include <vector>

using integer = long long;

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

void solve(std::vector<int>& a)
{
    integer s = 0, q = 0;
    for (int& x : a) {
        if (x < 0) {
            ++q;
            x = -x;
        }
        s += x;
    }

    if (q % 2 == 1)
        s -= *std::min_element(a.begin(), a.end()) * 2;

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
