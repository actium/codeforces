#include <iostream>
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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<std::vector<size_t>> t(n+1, std::vector<size_t>(20, n));
    {
        for (size_t i = n; i > 0; --i) {
            for (size_t j = 0; j < 20; ++j) {
                if ((a[i-1] & 1 << j) != 0)
                    t[i-1][j] = i-1;
                else
                    t[i-1][j] = t[i][j];
            }
        }
    }

    const auto jump = [&](unsigned x, size_t p) {
        size_t j = n;
        for (size_t i = 0; i < 20; ++i) {
            if ((x & 1 << i) == 0)
                j = std::min(j, t[p][i]);
        }
        return j;
    };

    unsigned v[1048576] = {}, q = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned x = 0;
        for (size_t j = i; j < n; j = jump(x, j)) {
            x |= a[j];
            q += (v[x]++ == 0);
        }
    }

    answer(q);
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
