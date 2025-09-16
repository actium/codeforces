#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void solve(std::vector<unsigned>& a)
{
    std::vector<unsigned> b[2];
    for (const unsigned x : a)
        b[x % 2].push_back(x);

    if (b[1].empty())
        return answer(0);

    std::sort(b[1].begin(), b[1].end());
    b[1].erase(b[1].begin(), b[1].begin() + b[1].size() / 2);

    integer k = 0;
    for (size_t i = 0; i < 2; ++i) {
        for (const unsigned x : b[i])
            k += x;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
