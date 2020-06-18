#include <iostream>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    std::vector<unsigned> row(n, 1);
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < n; ++j) {
            row[j] += row[j-1];
        }
    }

    answer(row.back());
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

