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

void solve(std::vector<unsigned>& r, size_t k)
{
    const size_t n = r.size();

    for (size_t i = 1; i+1 < n && k > 0; i += 2) {
        if (r[i] - 1 > r[i-1] && r[i] - 1 > r[i+1]) {
            --r[i];
            --k;
        }
    }

    answer(r);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> r(2 * n + 1);
    std::cin >> r;

    solve(r, k);

    return 0;
}

