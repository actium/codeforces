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

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, unsigned m, unsigned k)
{
    std::sort(a.begin(), a.end());

    unsigned c = 0;
    while (k < m && !a.empty()) {
        k += a.back() - 1;
        a.pop_back();
        ++c;
    }

    answer(k < m ? -1 : c);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned m, k;
    std::cin >> m >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m, k);

    return 0;
}

