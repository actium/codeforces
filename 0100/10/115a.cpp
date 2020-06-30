#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& p)
{
    size_t k = 0;
    for (int x : p) {
        size_t c = 1;
        while (x != -1) {
            ++c;
            x = p[x-1];
        }
        k = std::max(k, c);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}

