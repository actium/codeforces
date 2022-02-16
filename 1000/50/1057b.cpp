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

void solve(const std::vector<unsigned>& r)
{
    const size_t n = r.size();

    std::vector<unsigned> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + r[i];

    unsigned d = 0;
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (ps[i] - ps[j] > 100 * (i - j))
                d = std::max<unsigned>(d, i - j);
        }
    }

    answer(d);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}
