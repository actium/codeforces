#include <iostream>
#include <vector>

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

void solve(const std::vector<std::string>& c)
{
    const size_t n = c.size();

    const auto d = [](const std::string& a, const std::string& b) {
        unsigned k = 0;
        for (size_t i = 0; i < 6; ++i)
            k += (a[i] != b[i]);

        return (k + 1) / 2;
    };

    unsigned k = 6;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j)
            k = std::min(k, d(c[i], c[j]) - 1);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> c(n);
    std::cin >> c;

    solve(c);

    return 0;
}
