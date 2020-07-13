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

void solve(std::vector<unsigned>& b, unsigned d)
{
    const size_t n = b.size();

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i) {
        if (b[i] > b[i-1])
            continue;

        const unsigned c = (b[i-1] - b[i] + d) / d;
        b[i] += c * d, k += c;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned d;
    std::cin >> d;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(b, d);

    return 0;
}

