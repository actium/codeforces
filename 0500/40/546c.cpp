#include <iostream>
#include <set>

class Deck {
public:
    explicit Deck(std::istream& input)
    {
        size_t k;
        for (std::cin >> k; k != 0; --k) {
            unsigned x;
            std::cin >> x;
            push_back(x);
        }
    }

    unsigned size() const
    {
        return data & 0xF;
    }

    void push_back(unsigned x)
    {
        const unsigned k = size();
        data |= uint64_t(x) << 4 * (k + 1);
        ++data;
    }

    unsigned pop_front()
    {
        const unsigned k = size(), x = (data >> 4) & 0xF;
        data = data >> 4 & ~0xF | k - 1;
        return x;
    }

    bool operator <(const Deck& deck) const
    {
        return data < deck.data;
    }

private:
    uint64_t data = 0;

}; // class Deck

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const Deck& a, const Deck& b)
{
    unsigned k = 0;

    std::pair<Deck, Deck> p = { a, b };
    for (std::set<std::pair<Deck, Deck>> s; p.first.size() > 0 && p.second.size() > 0 && s.count(p) == 0; ++k) {
        s.insert(p);

        const unsigned x = p.first.pop_front(), y = p.second.pop_front();
        if (x > y) {
            p.first.push_back(y);
            p.first.push_back(x);
        }
        if (x < y) {
            p.second.push_back(x);
            p.second.push_back(y);
        }
    }

    if (p.first.size() == 0)
        return answer(k, 2);

    if (p.second.size() == 0)
        return answer(k, 1);

    no_answer();
}

int main()
{
    size_t n;
    std::cin >> n;

    Deck a(std::cin), b(std::cin);

    solve(a, b);

    return 0;
}
