#include <iostream>
#include <string>

void solve(unsigned n)
{
    do {
        unsigned d = n % 10;

        if (d < 5) {
            std::cout << "O-|";
        } else {
            std::cout << "-O|";
            d -= 5;
        }

        std::cout << std::string(d, 'O') << '-' << std::string(4 - d, 'O') << '\n';

        n /= 10;
    } while (n != 0);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

