#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    const auto optimize = [](unsigned x) {
        unsigned k = 16;
        for (unsigned d = 0; d < 16; ++d) {
            const unsigned long long q = x + d;
            for (unsigned s = 0; s < 16; ++s) {
                if ((q << s) % 32768 == 0)
                    k = std::min(k, d + s);
            }
        }
        return k;
    };

    std::vector<unsigned> q(n);
    for (size_t i = 0; i < n; ++i)
        q[i] = optimize(a[i]);

    answer(q);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

