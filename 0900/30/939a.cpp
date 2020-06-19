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

void solve(const std::vector<size_t>& f)
{
    const size_t n = f.size();

    for (size_t i = 0; i < n; ++i) {
        const size_t x = f[i] - 1;
        const size_t y = f[x] - 1;
        const size_t z = f[y] - 1;
        if (z == i)
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> f(n);
    std::cin >> f;

    solve(f);

    return 0;
}

