#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(const std::vector<unsigned>& a, size_t n)
{
    const size_t k = a.size();

    bool used[900] = {};
    for (const unsigned x : a)
        used[x-1] = true;

    size_t p = 0;
    for (const unsigned x : a) {
        std::cout << x;
        for (size_t i = 1; i < n; ++i) {
            while (used[p])
                ++p;

            std::cout << ' ' << 1 + p;
            used[p] = true;
        }
        std::cout << '\n';
    }
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(k);
    std::cin >> a;

    solve(a, n);

    return 0;
}

