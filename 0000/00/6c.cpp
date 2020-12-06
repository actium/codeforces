#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<unsigned>& t)
{
    const size_t n = t.size();

    size_t i = 0, j = 0;
    for (unsigned t1 = 0, t2 = 0; i + j < n; ) {
        if (t1 <= t2)
            t1 += t[i++];
        else
            t2 += t[n - ++j];
    }

    answer(i, j);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}

