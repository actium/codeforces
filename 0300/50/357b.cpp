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

void solve(size_t n, const std::vector<std::vector<unsigned>>& d)
{
    const size_t m = d.size();

    std::vector<unsigned> c(n);
    for (const auto& v : d) {
        for (const unsigned x : v) {
            if (c[x-1] != 0)
                continue;

            unsigned q = 1;
            while (c[v[0]-1] == q || c[v[1]-1] == q || c[v[2]-1] == q)
                ++q;

            c[x-1] = q;
        }
    }

    answer(c);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> d(m, std::vector<unsigned>(3));
    std::cin >> d;

    solve(n, d);

    return 0;
}
