#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

class Matrix {
public:
    Matrix(size_t _dim_x, size_t _dim_y) :
        dim_x(_dim_x), dim_y(_dim_y), data(gen_test_matrix(_dim_x, _dim_y)) {}

    Matrix(size_t _dim_x, size_t _dim_y, std::vector<int> &v) :
        dim_x(_dim_x), dim_y(_dim_y), data(v) {}

    // Matrix(size_t _dim_x, size_t _dim_y)

    // Matrix(const std::vector<int> &input);
    Matrix(const Matrix &m) :
        dim_x(m.dim_x),
        dim_y(m.dim_y),
        data(m.data) {};

    ~Matrix() {}
    
    void set_value(size_t x, size_t y, int val) { data[get_index(x, y)] = val; }
    int get_value(size_t x, size_t y) { return data.at(get_index(x, y)); }
    int &get_ref(size_t x, size_t y) { return data[get_index(x, y)]; }
    size_t get_index(size_t x, size_t y) const { return dim_y * x + y; }

    size_t get_x() const { return this->dim_x; }
    size_t get_y() const { return this->dim_y; }

    int rng_num(int min = 50, int max = 500) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(gen);
    }

    std::vector<int> gen_test_matrix(size_t size_x, size_t size_y) {

        std::vector<int> rng(size_x * size_y);
        std::generate(rng.begin(), rng.end(), [=](){ return rng_num(); });

        return rng;
    }

    inline bool operator==(const Matrix &rhs) {
        return rhs.get_x() == get_x() && rhs.get_y() == get_y();
    }

    Matrix operator+(const Matrix &rhs) {
        std::vector<int> v(this->data.size());
        auto lambda = [](int a, int b){ return a + b; };
        /* if(this == &rhs) {
            auto multiply = [](int a){ return a * 2; };
            std::transform(this->data.begin(), this->data.end(), v.begin(), multiply);
            return Matrix(get_x(), get_y(), v);
        } */
        std::transform(this->data.begin(), this->data.end(), rhs.data.begin(), v.begin(), lambda);
        return Matrix(get_x(), get_y(), v);
    };

    void print() {
        for (size_t y = 0; y < dim_y; ++y) {
            for (size_t x = 0; x < dim_x; ++x) {
                std::cout << data[get_index(x, y)] << " ";
            }
        std::cout << std::endl;
        }
    };

private:
    size_t dim_x;
    size_t dim_y;
    std::vector<int> data;
};
