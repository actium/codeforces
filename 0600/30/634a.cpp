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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    size_t i = 0;
    while (a[i] != b[b.front() == 0])
        ++i;

    for (size_t j = 0; j < n; ++j) {
        if (b[j] == 0)
            continue;

        if (a[i] == 0 && ++i == n)
            i = 0;

        if (a[i] != b[j])
            return answer(false);

        if (++i == n)
            i = 0;
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

