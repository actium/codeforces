#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& m, unsigned f, unsigned a, unsigned b)
{
    unsigned t = 0;
    for (const unsigned x : m) {
        const unsigned d = std::min(1ull * (x - t) * a, 1ull * b);
        if (d >= f)
            return answer(false);

        f -= d;
        t = x;
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned f, a, b;
    std::cin >> f >> a >> b;

    std::vector<unsigned> m(n);
    std::cin >> m;

    solve(m, f, a, b);
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
