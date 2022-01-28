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
    constexpr const char* s[2] = { "no", "yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<int>& x)
{
    const size_t n = x.size();

    for (size_t i = 1; i < n; ++i) {
        const int x1 = x[i-1], x2 = x[i];

        for (size_t j = i + 2; j < n; ++j) {
            const int x3 = x[j-1], x4 = x[j];

            const bool a = (x1 - x3 < 0) == (x2 - x3 < 0);
            const bool b = (x1 - x4 < 0) == (x2 - x4 < 0);
            if (a != b)
                return answer(true);
        }
    }

    answer(false);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> x(n);
    std::cin >> x;

    solve(x);

    return 0;
}
