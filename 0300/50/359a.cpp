#include <iostream>
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

void solve(const std::vector<std::vector<int>>& a, size_t m)
{
    const size_t n = a.size();

    for (size_t j = 1; j < m-1; ++j) {
        if (a.front()[j] == 1 || a.back()[j] == 1)
            return answer(2);
    }

    for (size_t i = 1; i < n-1; ++i) {
        if (a[i][0] == 1 || a[i][m-1] == 1)
            return answer(2);
    }

    answer(4);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    std::cin >> a;

    solve(a, m);

    return 0;
}

