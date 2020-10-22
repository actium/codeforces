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

void solve(const std::vector<unsigned>& t, unsigned m)
{
    const size_t n = t.size();

    std::vector<unsigned> c(n);
    unsigned s = 0, f[100] = {};
    for (size_t i = 0; i < n; ++i) {
        s += t[i];
        if (s > m) {
            for (unsigned x = 100, d = s - m; d > 0; --x) {
                const unsigned q = x * f[x-1];
                if (d <= q) {
                    c[i] += (d + x - 1) / x;
                    d = 0;
                } else {
                    c[i] += f[x-1];
                    d -= q;
                }
            }
        }
        ++f[t[i]-1];
    }

    answer(c);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t, m);

    return 0;
}

