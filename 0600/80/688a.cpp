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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& v, size_t n)
{
    const size_t d = v.size();

    size_t count = 0;
    for (size_t i = 0, c = 0; i < d; ++i) {
        if (v[i] == std::string(n, '1')) {
            c = 0;
        } else {
            ++c;
        }
        count = std::max(count, c);
    }

    answer(count);
}

int main()
{
    size_t n, d;
    std::cin >> n >> d;

    std::vector<std::string> v(d);
    std::cin >> v;

    solve(v, n);

    return 0;
}

