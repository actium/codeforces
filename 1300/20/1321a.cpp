#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& r, const std::vector<unsigned>& b)
{
    const size_t n = r.size();

    size_t f[2] = {};
    for (size_t i = 0; i < n; ++i) {
        if (r[i] == b[i])
            continue;

        ++f[r[i] < b[i]];
    }

    if (f[0] == 0)
        answer(-1);
    else
        answer(f[1] / f[0] + 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> r(n);
    std::cin >> r;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(r, b);

    return 0;
}

