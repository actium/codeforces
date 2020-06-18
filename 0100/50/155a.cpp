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

void solve(const std::vector<unsigned>& v)
{
    const size_t n = v.size();

    size_t count = 0;

    unsigned min = v[0], max = v[0];
    for (size_t i = 1; i < n; ++i) {
        if (v[i] < min) {
            min = v[i];
            ++count;
        }
        if (v[i] > max) {
            max = v[i];
            ++count;
        }
    }

    answer(count);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> v(n);
    std::cin >> v;

    solve(v);

    return 0;
}

