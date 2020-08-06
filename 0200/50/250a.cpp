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
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<int>& a)
{
    std::vector<unsigned> b;

    unsigned d = 0;
    for (const int x : a) {
        if (b.empty())
            b.push_back(0);

        if (x < 0 && ++d == 3) {
            b.push_back(0);
            d = 1;
        }

        ++b.back();
    }

    answer(b);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

