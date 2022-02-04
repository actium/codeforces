#include <iostream>
#include <queue>
#include <vector>

struct Customer {
    unsigned m;
    size_t i;
};

bool operator <(const Customer& a, const Customer& b)
{
    if (a.m != b.m)
        return a.m < b.m;

    return a.i > b.i;
}

void answer(size_t x)
{
    std::cout << 1+x << '\n';
}

int main()
{
    size_t q;
    std::cin >> q;

    std::priority_queue<Customer> c;
    std::vector<unsigned> x;
    for (size_t i = 0, j = 0; i < q; ++i) {
        unsigned t;
        std::cin >> t;

        if (t == 1) {
            unsigned m;
            std::cin >> m;

            c.push({ m, x.size() });
            x.push_back(m);
        }
        if (t == 2) {
            while (x[j] == 0)
                ++j;

            answer(j);
            x[j] = 0;
        }
        if (t == 3) {
            while (x[c.top().i] == 0)
                c.pop();

            answer(c.top().i);
            x[c.top().i] = 0;
        }
    }

    return 0;
}
