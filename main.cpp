#include <iostream>
#include "n_dim_vector_very_template.cpp"

using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<int> coords;
    coords.resize(4, 1);
    VectorN<int, 4> vector1 = VectorN<int, 4>(coords);
    coords.resize(0, 1);
    coords.resize(4, 2);
    VectorN<int, 4> vector2 = VectorN<int, 4>(coords);
    coords.resize(0, 1);
    coords.resize(4, 3);
    VectorN<int, 4> vector3 = VectorN<int, 4>(coords);
    cout << vector1 << vector2 << vector3 <<std::endl;

    auto vector4 =  vector1 + vector3;
    cout << vector4 << endl;
    vector4 =  vector1 * 3;
    cout << vector4 << endl;
    cout << (vector4 == vector3) << endl;

    coords.resize(0, 1);
    coords.resize(5, 2);
    VectorN<int, 5> vector5(coords);
    cout << vector5 << endl;
// тут нужно посмотреть, чтобы выдавало ошибку при сравнении векторов
    return 0;
}
