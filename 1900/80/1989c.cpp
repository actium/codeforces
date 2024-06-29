#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<int>& a, const std::vector<int>& b)
{
    const size_t n = a.size();

    int v[2] = {};
    {
        unsigned f[2] = {};
        for (size_t i = 0; i < n; ++i) {
            if (a[i] > b[i])
                v[0] += a[i];
            if (b[i] > a[i])
                v[1] += b[i];

            if (a[i] == -1 && b[i] == -1)
                ++f[0];
            if (a[i] == 1 && b[i] == 1)
                ++f[1];
        }

        while (f[0] != 0) {
            --v[v[1] > v[0]];
            --f[0];
        }
        while (f[1] != 0) {
            ++v[v[1] < v[0]];
            --f[1];
        }
    }

    answer(std::min(v[0], v[1]));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
