#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();
    const size_t m = a.front().size();

    unsigned s = 0;
    for (size_t i = n; i-- > 0; ) {
        for (size_t j = m; j-- > 0; ) {
            if (a[i][j] == 0)
                a[i][j] = std::min(a[i+1][j], a[i][j+1]) - 1;

            if (a[i][j] == 0 || (i+1 < n && a[i][j] >= a[i+1][j]) || (j+1 < m && a[i][j] >= a[i][j+1]))
                return no_answer();

            s += a[i][j];
        }
    }

    answer(s);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a);

    return 0;
}

