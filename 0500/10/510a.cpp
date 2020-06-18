#include <iostream>
#include <string>

void print_line(size_t r, size_t w)
{
    if (r % 2 == 0) {
        std::cout << std::string(w, '#') << '\n';
        return;
    }

    if (r % 4 == 1) {
        std::cout << std::string(w - 1, '.') << "#\n";
        return;
    }

    std::cout << '#' << std::string(w - 1, '.') << '\n';
}

void solve(size_t n, size_t m)
{
    for (size_t r = 0; r < n; ++r)
        print_line(r, m);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

