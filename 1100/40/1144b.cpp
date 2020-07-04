#include <algorithm>
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

void solve(const std::vector<unsigned>& a)
{
    std::vector<unsigned> b[2];
    for (const unsigned x : a)
        b[x % 2].push_back(x);

    if (b[0].size() == b[1].size())
        return answer(0);

    if (b[0].size() > b[1].size())
        b[0].swap(b[1]);

    std::sort(b[1].begin(), b[1].end());

    unsigned sum = 0;
    for (size_t i = 0; i < b[1].size() - b[0].size() - 1; ++i)
        sum += b[1][i];

    answer(sum);
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

