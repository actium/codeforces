#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

struct Ratio {
    int a;
    int b;

    Ratio(int x, int y)
        : a(x)
        , b(y)
    {
        if (b < 0) {
            a = -a;
            b = -b;
        }
    }
};

bool operator <(const Ratio& lhs, const Ratio& rhs)
{
    return 1LL * lhs.a * rhs.b < 1LL * rhs.a * lhs.b;
}

void solve(const std::vector<int>& a, const std::vector<int>& b)
{
    const size_t n = a.size();

    unsigned k = 0, z = 0;

    std::map<Ratio, unsigned> f;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 0)
            z += (b[i] == 0);
        else
            k = std::max(k, ++f[Ratio(-b[i], a[i])]);
    }

    answer(k + z);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
