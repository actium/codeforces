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

    std::vector<long long> a(n);
    std::cin >> a;

    long long d = 0;
    for (size_t i = 0; i < m; ++i) {
        unsigned t;
        std::cin >> t;

        if (t == 1) {
            unsigned v, x;
            std::cin >> v >> x;

            a[v-1] = x - d;
        }
        if (t == 2) {
            unsigned y;
            std::cin >> y;

            d += y;
        }
        if (t == 3) {
            unsigned q;
            std::cin >> q;

            std::cout << a[q-1] + d << '\n';
        }
    }

    return 0;
}

