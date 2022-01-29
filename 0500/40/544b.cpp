#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    std::cout << "YES" << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(size_t n, size_t k)
{
    std::vector<std::string> b(n, std::string(n, 'S'));
    for (size_t i = 0; i < n && k != 0; ++i) {
        for (size_t j = 0; j < n && k != 0; ++j) {
            if ((i + j) % 2 == 0) {
                b[i][j] = 'L';
                --k;
            }
        }
    }

    if (k == 0)
        return answer(b);

    no_answer();
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
