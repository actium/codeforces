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

    std::vector<size_t> b;
    for (size_t i = 0; i < n && b.size() != 2; ++i) {
        if (a[i] == 1 || a[i] == n)
            b.push_back(i);
    }

    answer(std::max(b.back(), n-1 - b.front()));
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

