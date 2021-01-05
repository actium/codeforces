#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& a, const std::vector<unsigned>& d)
{
    const size_t n = a.length();

    size_t i = 0;
    for ( ; i < n; ++i) {
        const unsigned x = a[i] - '0';
        if (x < d[x-1])
            break;
    }
    for ( ; i < n; ++i) {
        const unsigned x = a[i] - '0';
        if (x > d[x-1])
            break;

        a[i] = '0' + d[x-1];
    }

    answer(a);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string a;
    std::cin >> a;

    std::vector<unsigned> d(9);
    std::cin >> d;

    solve(a, d);

    return 0;
}

