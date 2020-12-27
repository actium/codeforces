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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    const auto check = [&](size_t i) {
        constexpr unsigned p[] = {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
            31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
        };

        for (size_t j = 0; j < n; ++j) {
            if (p[(i + j) % 48] != a[j])
                return false;
        }
        return true;
    };

    for (size_t i = 0; i < 48; ++i) {
        if (check(i))
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

