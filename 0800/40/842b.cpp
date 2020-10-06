#include <iostream>
#include <vector>

struct Piece {
    unsigned x;
    unsigned y;
    unsigned r;
};

std::istream& operator >>(std::istream& input, Piece& v)
{
    return input >> v.x >> v.y >> v.r;
}

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

void solve(unsigned r, unsigned d, const std::vector<Piece>& p)
{
    unsigned k = 0;
    for (const Piece& q : p) {
        if (2 * q.r > d)
            continue;

        const unsigned a = q.x * q.x + q.y * q.y;
        const unsigned b = r - d + q.r;
        const unsigned c = r - q.r;
        if (a >= b * b && a <= c * c)
            ++k;
    }

    answer(k);
}

int main()
{
    unsigned r, d;
    std::cin >> r >> d;

    size_t n;
    std::cin >> n;

    std::vector<Piece> p(n);
    std::cin >> p;

    solve(r, d, p);

    return 0;
}

