#include <iostream>
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

unsigned evaluate(unsigned x, unsigned y)
{
    return x < y ? y - x : x - y;
}

unsigned search(unsigned x, const std::vector<unsigned>& c)
{
    unsigned v = ~0u;
    for (const unsigned y : c)
        v = std::min(v, evaluate(x, y));

    return v;
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    const unsigned c[4] = {
        search(a[0], b),
        search(a[n-1], b),
        search(b[0], a),
        search(b[n-1], a),
    };

    unsigned v = c[0] + c[1] + c[2] + c[3];
    v = std::min(v, evaluate(a[0], b[0]) + c[1] + c[3]);
    v = std::min(v, evaluate(a[0], b[n-1]) + c[1] + c[2]);
    v = std::min(v, c[0] + evaluate(a[n-1], b[0]) + c[3]);
    v = std::min(v, c[0] + evaluate(a[n-1], b[n-1]) + c[2]);
    v = std::min(v, evaluate(a[0], b[0]) + evaluate(a[n-1], b[n-1]));
    v = std::min(v, evaluate(a[0], b[n-1]) + evaluate(a[n-1], b[0]));

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
