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

void solve(const std::vector<unsigned>& x, size_t p)
{
    const size_t n = x.size();

    std::vector<bool> z(p);
    for (size_t i = 0; i < n; ++i) {
        const size_t h = x[i] % p;
        if (z[h])
            return answer(1 + i);

        z[h] = true;
    }

    answer(-1);
}

int main()
{
    size_t p, n;
    std::cin >> p >> n;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x, p);

    return 0;
}

