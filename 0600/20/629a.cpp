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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& c)
{
    const size_t n = c.size();

    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = j+1; k < n; ++k) {
                if (c[i][j] == 'C' && c[i][k] == 'C')
                    ++count;

                if (c[j][i] == 'C' && c[k][i] == 'C')
                    ++count;
            }
        }
    }

    answer(count);
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

