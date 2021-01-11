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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    a.insert(a.begin(), 1, 0);
    a.insert(a.end(), 1, 1001);

    unsigned c = 0, k = 0;
    for (size_t i = 1; i <= n; ++i) {
        if (a[i-1] + 1 == a[i] && a[i] + 1 == a[i+1]) {
            k = std::max(k, ++c);
        } else {
            c = 0;
        }
    }

    answer(k);
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

