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
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n, const std::vector<unsigned>& c, unsigned d)
{
    const size_t m = c.size();

    std::vector<unsigned> p(1+m);
    for (size_t i = 0; i < m; ++i)
        p[i+1] = p[i] + c[i];

    std::vector<unsigned> v(n);
    for (size_t i = m, x = n+1; x != 0; ) {
        if (p[i] + d >= x) {
            for (x = p[i]; i != 0; --i) {
                while (x > p[i-1])
                    v[--x] = i;
            }
        } else {
            if (i-- == 0)
                return no_answer();

            x -= d;
            for (size_t k = 0; k < c[i]; ++k)
                v[--x] = i+1;

            ++x;
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m, d;
    std::cin >> n >> m >> d;

    std::vector<unsigned> c(m);
    std::cin >> c;

    solve(n, c, d);

    return 0;
}
