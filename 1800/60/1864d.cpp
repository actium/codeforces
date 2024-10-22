#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

inline unsigned lsb(unsigned x)
{
    return x & -x;
}

class InversionFrequencyMap {
public:
    explicit InversionFrequencyMap(unsigned size)
        : size_(size)
        , data_(1 + size, std::vector<unsigned>(1 + size))
    {}

    void update(unsigned r, unsigned c)
    {
        for (unsigned i = 1 + r; i <= size_; i += lsb(i)) {
            for (unsigned j = 1 + c; j <= size_; j += lsb(j))
                ++data_[i][j];
        }
    }

    unsigned count(unsigned r, unsigned c) const
    {
        unsigned sum = 0;
        for (unsigned i = 1 + r; i > 0; i &= i - 1) {
            for (unsigned j = 1 + c; j > 0; j &= j - 1)
                sum += data_[i][j];
        }
        return sum;
    }

    unsigned count(unsigned sr, unsigned sc, unsigned tr, unsigned tc) const
    {
        unsigned sum = 0;
        sum += count(tr, tc);
        sum -= count(sr - 1, tc);
        sum -= count(tr, sc - 1);
        sum += count(sr - 1, sc - 1);
        return sum;
    }

private:
    const unsigned size_;

    std::vector<std::vector<unsigned>> data_;

}; // class InversionFrequencyMap

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size();

    unsigned k = 0;
    {
        InversionFrequencyMap map(2 * n);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                const unsigned v = g[i][j] - '0' + map.count(0, 0, n-1+i-j, i+j);
                if (v % 2 == 1) {
                    map.update(n-1+i-j, i+j);
                    ++k;
                }
            }
        }
    }
    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
