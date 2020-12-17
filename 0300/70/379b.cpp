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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::string c = "R";
    for (size_t x = 1; x < n; ) {
        if (a[x] > 0 && c.back() != 'P') {
            c.push_back('P');
            --a[x];
        }
        if ((x > 0 && a[x-1] != 0) || (x == n-1 && a[x] > 0)) {
            c.push_back('L');
            --x;
        } else {
            c.push_back('R');
            ++x;
        }
    }

    while (c.back() != 'P')
        c.pop_back();

    answer(c);
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

