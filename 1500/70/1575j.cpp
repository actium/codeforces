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

void solve(std::vector<std::vector<unsigned>>& a, std::vector<unsigned>& c)
{
    const size_t n = a.size(), k = c.size();

    for (size_t i = 0; i < k; ++i) {
        size_t x = c[i] - 1;
        for (size_t r = 0; r < n; ) {
            switch (a[r][x]) {
                case 1:
                    a[r][x] = 2;
                    ++x;
                    break;

                case 2:
                    ++r;
                    break;

                case 3:
                    a[r][x] = 2;
                    --x;
                    break;
            }
        }
        c[i] = x + 1;
    }

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    std::vector<unsigned> c(k);
    std::cin >> c;

    solve(a, c);

    return 0;
}
