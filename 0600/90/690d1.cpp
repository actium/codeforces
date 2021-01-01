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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& r)
{
    const size_t w = r.length();

    unsigned k = (r[0] == 'B');
    for (size_t i = 1; i < w; ++i) {
        if (r[i] == 'B' && r[i-1] != 'B')
            ++k;
    }

    answer(k);
}

int main()
{
    size_t r, c;
    std::cin >> r >> c;

    std::vector<std::string> b(r);
    std::cin >> b;

    solve(b.back());

    return 0;
}

