#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

bool check(const std::vector<std::vector<unsigned>>& a, size_t i, size_t j)
{
    if (a[i][j] == 1)
        return true;

    const size_t n = a.size();
    for (size_t s = 0; s < n; ++s) {
        for (size_t t = 0; t < n; ++t) {
            if (a[i][s] + a[t][j] == a[i][j])
                return true;
        }
    }
    return false;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (!check(a, i, j))
                return answer(false);
        }
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
    std::cin >> a;

    solve(a);

    return 0;
}

