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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, size_t s)
{
    const size_t n = a.size();

    if (a[0] == 0)
        return answer(false);

    if (a[s-1] == 1)
        return answer(true);

    if (b[s-1] == 0)
        return answer(false);

    for (size_t i = s; i < n; ++i) {
        if (a[i] == 1 && b[i] == 1)
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n, s;
    std::cin >> n >> s;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b, s);

    return 0;
}

