#include <algorithm>
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

bool test(char a, char b, char c, char d)
{
    char batch[4] = { a, b, c, d };
    std::sort(std::begin(batch), std::end(batch));
    return batch[3] == 'f' && batch[0] == 'a' && batch[1] == 'c' && batch[2] == 'e'; 
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& image, size_t m)
{
    const size_t n = image.size();

    unsigned c = 0;
    for (size_t i = 0; i < n-1; ++i) {
        for (size_t j = 0; j < m-1; ++j) {
            c += test(image[i][j], image[i][j+1], image[i+1][j], image[i+1][j+1]);
        }
    }

    answer(c);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> image(n);
    std::cin >> image;

    solve(image, m);

    return 0;
}

