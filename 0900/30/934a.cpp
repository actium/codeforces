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

void solve(std::vector<integer>& a, std::vector<integer>& b)
{
    const size_t n = a.size(), m = b.size();

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    if (a[0] >= 0 && b[0] >= 0)
        return answer(a[n-2] * b[m-1]);

    if (a[n-1] <= 0 && b[m-1] <= 0)
        return answer(a[1] * b[0]);

    if (a[n-1] <= 0 && b[0] >= 0)
        return answer(a[n-2] * b[0]);

    if (a[0] >= 0 && b[m-1] <= 0)
        return answer(a[1] * b[m-1]);

    const integer c1 = std::max(a[1] * b[0], a[n-1] * b[m-1]);
    const integer c2 = std::max(a[0] * b[0], a[n-2] * b[m-1]);

    answer(std::min(c1, c2));
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<integer> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
