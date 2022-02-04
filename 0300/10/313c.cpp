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
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    std::vector<integer> s(1+n);
    for (size_t i = 0; i < n; ++i)
        s[i+1] = s[i] + a[i];

    integer t = 0;
    for (size_t k = a.size(); k != 0; k /= 4)
        t += s[k];

    answer(t);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t q;
    std::cin >> q;

    std::vector<unsigned> a(q);
    std::cin >> a;

    solve(a);

    return 0;
}
