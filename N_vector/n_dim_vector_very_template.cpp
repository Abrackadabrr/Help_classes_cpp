#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::istream;
using std::ostream;
using std::vector;

template<typename type, unsigned int dimension>
class VectorN{
private:
    vector<type> coords;
public:
    VectorN();
    VectorN(const vector<type>& coords);
    ~VectorN();

    type getValue(unsigned int i) const;
    void setValue(unsigned int i, type value);

    bool operator == (const VectorN<type, dimension>& vector);
    bool operator != (const VectorN<type, dimension>& vector);
    VectorN<type, dimension> operator + (const VectorN<type, dimension>& vectorN);
    VectorN<type, dimension> operator * (int k);

    template<typename typ, unsigned int dimensio>
    friend VectorN<typ, dimensio> operator *(int k, const VectorN<typ, dimensio>& vectorN);
    friend istream &operator >> (istream &in, VectorN<type, dimension> &vectorN);
};

template<typename type, unsigned int dimension>
VectorN<type, dimension>::VectorN() {
    this->coords.resize(dimension, 0);
}

template<typename type, unsigned int dimension>
VectorN<type, dimension>::VectorN(const vector<type> &coords){
    this->coords.resize(0);
    this->coords.reserve(4);
    for (int v: coords) {
        this->coords.push_back(v);
    }
}

template<typename type, unsigned int dimension>
type VectorN<type, dimension>::getValue(unsigned int i) const {
    return this->coords[i];
}

template<typename type, unsigned int dimension>
void VectorN<type, dimension>::setValue(unsigned int i, type value) {
    this->coords[i] = value;
}

template<typename type, unsigned int dimension>
bool VectorN<type, dimension>::operator==(const VectorN<type, dimension>& vector) {
    for (unsigned int i = 0; i < dimension; i++)
        if (this->coords[i] != vector.coords[i]) return false;
    return true;
}

template<typename type, unsigned int dimension>
bool VectorN<type, dimension>::operator!=(const VectorN<type, dimension>& vector) {
    return !(*this == vector);
}

template<typename type, unsigned int dimension>
VectorN<type, dimension> VectorN<type, dimension>::operator+(const VectorN<type, dimension>& vectorN) {
    vector<type> sum_coords;
    sum_coords.reserve(dimension);
    for (unsigned int i = 0; i < dimension; i++)
        sum_coords.push_back((this->coords[i] + vectorN.coords[i]));
    return VectorN(sum_coords);
}

template<typename type, unsigned int dimension>
VectorN<type, dimension> VectorN<type, dimension>::operator*(int k) {
    vector<type> sum_coords;
    sum_coords.reserve(dimension);
    for (unsigned int i = 0; i < dimension; i++)
        sum_coords.push_back(this->coords[i]*k);
    return VectorN(sum_coords);
}

template<typename type, unsigned int dimension>
VectorN<type, dimension> operator *(int k, const VectorN<type, dimension>& vectorN) {
    vector<type> sum_coords;
    sum_coords.reserve(dimension);
    for (unsigned int i = 0; i < dimension; i++)
        sum_coords.push_back(vectorN.coords[i]*k);
    return VectorN<type, dimension>(sum_coords);
}


template<typename type, unsigned int dimension>
istream &operator >> (istream &in, VectorN<type, dimension> &vectorN) {
    return in;
}

// example: {4, (5, 5, 5, 5)}
template<typename type, unsigned int dimension>
ostream &operator << (ostream &of, const VectorN<type, dimension> &vectorN) {
    of << "{dim: " << dimension << "; (";
    for(unsigned int i = 0; i < dimension - 1; i++)
        of << vectorN.getValue(i)<< ", ";
    of << vectorN.getValue(dimension-1) << ")" << "} ";
    return of;
}

template<typename type, unsigned int dimension>
VectorN<type, dimension>::~VectorN() = default;
