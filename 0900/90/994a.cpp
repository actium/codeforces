#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> x(n);
    std::cin >> x;

    bool y[10] = {};
    for (size_t i = 0; i < m; ++i) {
        size_t a;
        std::cin >> a;

        y[a] = true;
    }

    const char* separator = "";
    for (const size_t d : x) {
        if (y[d]) {
            std::cout << separator << d;
            separator = " ";
        }
    }
    std::cout << '\n';

    return 0;
}

