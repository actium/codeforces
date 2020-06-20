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
    std::cout << 1 + v << '\n';
}

void solve(const std::vector<unsigned>& d)
{
    const size_t n = d.size();

    const size_t target = 1 - d.back();
    for (size_t i = n; i-- > 0; ) {
        if (d[i] == target)
            return answer(i);
    }

    answer(0);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(d);

    return 0;
}

