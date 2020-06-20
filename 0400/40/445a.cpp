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

void solve(const std::vector<std::string>& b, size_t m)
{
    const size_t n = b.size();

    for (size_t r = 0; r < n; ++r) {
        const std::string& row = b[r];

        std::string d;
        for (size_t c = 0; c < m; ++c) {
            if (row[c] == '-') {
                d.push_back('-');
            } else {
                d.push_back((r + c) % 2 == 0 ? 'B' : 'W');
            }
        }
        std::cout << d << '\n';
    }
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b, m);

    return 0;
}

