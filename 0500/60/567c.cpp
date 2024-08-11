#include <iostream>
#include <map>
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

void solve(const std::vector<int>& a, int k)
{
    integer q = 0;
    {
        std::map<int, integer> f[2];
        for (const int x : a) {
            if (x % (1ll * k * k) == 0)
                q += f[1][x / k];

            if (x % k == 0)
                f[1][x] += f[0][x / k];

            f[0][x] += 1;
        }
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    int k;
    std::cin >> k;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
