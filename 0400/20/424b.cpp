#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Locality {
    int x;
    int y;
    unsigned k;
};

std::istream& operator >>(std::istream& input, Locality& v)
{
    return input >> v.x >> v.y >> v.k;
}

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<Locality>& a, unsigned s)
{
    const auto f = [&a](double r) {
        unsigned k = 0;
        for (const auto& q : a) {
            if (q.x * q.x + q.y * q.y <= r * r)
                k += q.k;
        }
        return k;
    };

    double lb = 0, ub = 15000;
    for (unsigned i = 0; i < 50; ++i) {
        const double r = (lb + ub) / 2;
        if (s + f(r) < 1000000)
            lb = r;
        else
            ub = r;
    }

    if (ub < 15000)
        return answer(ub);

    no_answer();
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    std::vector<Locality> a(n);
    std::cin >> a;

    solve(a, s);

    return 0;
}

