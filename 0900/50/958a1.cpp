#include <iostream>
#include <string>
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
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

std::vector<std::string> rotate(const std::vector<std::string>& m)
{
    const size_t n = m.size();

    std::vector<std::string> r = m;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            r[i][j] = m[n-1-j][i];
    }
    return r;
}

std::vector<std::string> flip(const std::vector<std::string>& m)
{
    const size_t n = m.size();

    std::vector<std::string> r = m;
    for (size_t i = 0; i < n / 2; ++i)
        std::swap(r[i], r[n-1-i]);

    return r;
}

void solve(const std::vector<std::string>& a, std::vector<std::string>& b)
{
    for (size_t i = 0; i < 4; ++i) {
        b = rotate(b);

        if (a == b || a == flip(b))
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
