#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const size_t x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::vector<int>>& a)
{
    const size_t n = a.size();

    std::vector<size_t> g;
    for (size_t i = 0; i < n; ++i) {
        g.push_back(i);
        for (size_t j = 0; j < n; ++j) {
            if (a[i][j] == 1 || a[i][j] == 3) {
                g.pop_back();
                break;
            }
        }
    }

    answer(g);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    std::cin >> a;

    solve(a);

    return 0;
}

