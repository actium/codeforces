#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& t)
{
    const size_t n = t.size();

    size_t c[2] = { 1, 0 }, k = 0, max = 0;
    for (size_t i = 1; i < n; ++i) {
        if (t[i] == t[i-1]) {
            ++c[k];
        } else {
            if (c[0] != 0 && c[1] != 0)
                max = std::max(max, 2 * std::min(c[0], c[1]));

            k ^= 1, c[k] = 1;
        }
    }

    answer(std::max(max, 2 * std::min(c[0], c[1])));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}

