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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a)
{
    size_t count = 0;
    while (!a.empty()) {
        std::sort(a.begin(), a.end());

        const unsigned x = a.front();
        for (size_t i = a.size(); i-- > 0; ) {
            if (a[i] % x == 0) {
                std::swap(a[i], a.back());
                a.pop_back();
            }
        }

        ++count;
    }

    answer(count);
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

