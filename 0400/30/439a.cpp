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

void solve(const std::vector<unsigned>& t, size_t d)
{
    const size_t n = t.size();

    unsigned s = 0;
    for (const unsigned x : t) {
        s += x;
    }

    if (s + (n - 1) * 10 > d) {
        answer(-1);
    } else {
        answer((d - s) / 5);
    }
}

int main()
{
    size_t n, d;
    std::cin >> n >> d;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t, d);

    return 0;
}

