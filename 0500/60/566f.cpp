#include <iostream>
#include <vector>

constexpr unsigned N = 1 + 1000000;

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
    unsigned v = 0;

    std::vector<unsigned> t(N);
    for (const unsigned x : a) {
        v = std::max(v, ++t[x]);

        for (unsigned i = 2 * x; i < N; i += x)
            t[i] = std::max(t[i], t[x]);
    }

    answer(v);
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
