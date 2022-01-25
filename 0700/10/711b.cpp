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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();

    if (n == 1)
        return answer(1);

    size_t r, c;

    std::vector<integer> rs(n+1), cs(n+1);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            rs[i] += a[i][j];
            cs[j] += a[i][j];

            if (a[i][j] == 0) {
                r = i;
                c = j;
            }
        }
        rs[n] += a[i][i];
        cs[n] += a[i][n-1-i];
    }

    if (rs[(r+1)%n] <= rs[r])
        return no_answer();

    const integer x = rs[(r+1)%n] - rs[r];
    rs[r] += x;
    cs[c] += x;

    if (r == c)
        rs[n] += x;
    if (r + c == n - 1)
        cs[n] += x;

    for (size_t i = 1; i <= n; ++i) {
        if (rs[i] != rs[i-1] || cs[i] != cs[i-1])
            return no_answer();
    }

    answer(x);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
    std::cin >> a;

    solve(a);

    return 0;
}
