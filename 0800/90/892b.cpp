#include <iostream>
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

void solve(const std::vector<unsigned>& l)
{
    unsigned k = 0;
    for (size_t i = l.size(), j = i; i-- > 0; ) {
        if (i < j)
            ++k;

        if (i < l[i])
            j = 0;
        else
            j = std::min(j, i - l[i]);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> l(n);
    std::cin >> l;

    solve(l);

    return 0;
}

