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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::string>& a)
{
    const size_t n = a.size();
    const size_t m = a.front().size();

    const auto P = [&](int i, int j) -> bool {
        return i >= 0 && i < n && j >= 0 && j < m && a[i][j] == 'P';
    };

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (a[i][j] == 'W')
                k += P(i-1, j) || P(i, j-1) || P(i, j+1) || P(i+1, j);
        }
    }

    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

