#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> b(n, ~0u);
    {
        std::vector<bool> v(n + 1);
        for (size_t i = 0, x = 0; i < n; ++i) {
            if (a[i] != x) {
                b[i] = x;
                x = a[i];
            }
            v[x] = true;
        }

        for (size_t i = 0, x = 1; i < n; ++i) {
            if (b[i] != ~0u)
                continue;

            while (v[x])
                ++x;

            b[i] = x++;
        }
    }

    answer(b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
