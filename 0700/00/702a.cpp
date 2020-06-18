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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t max_length = 1;
    for (size_t i = 1, length = 1; i < n; ++i) {
        if (a[i] > a[i-1])
            ++length;
        else
            length = 1;

        max_length = std::max(max_length, length);
    }

    answer(max_length);
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

