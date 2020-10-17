#include <iostream>
#include <queue>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer v)
{
    std::cout << v << '\n';
}

class Carrot {
public:
    Carrot(unsigned a)
        : a(a)
        , k(1)
    {}

    integer evaluate() const
    {
        const integer x = a / k;
        const unsigned r = a % k;

        return (k - r) * x * x + r * (x + 1) * (x + 1);
    }

    Carrot split() const
    {
        Carrot carrot(a);
        carrot.k = k + 1;
        return carrot;
    }

    bool operator <(const Carrot& carrot) const
    {
        return evaluate() - split().evaluate() < carrot.evaluate() - carrot.split().evaluate();
    }

private:
    unsigned a;
    unsigned k;

}; // class Carrot

void solve(std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::priority_queue<Carrot> carrots(a.cbegin(), a.cend());
    for (size_t d = k - n; d > 0; --d) {
        const Carrot carrot = carrots.top();
        carrots.pop();
        carrots.push(carrot.split());
    }

    integer s = 0;
    while (!carrots.empty()) {
        s += carrots.top().evaluate();
        carrots.pop();
    }

    answer(s);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

