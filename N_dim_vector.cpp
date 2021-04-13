//#include <iostream>
//#include <vector>
//#include <string>
//using std::string;
//using std::istream;
//using std::ostream;
//using std::vector;
//
//template<typename type>
//class VectorN
//{
//private:
//    unsigned int dimension;
//    vector<type> coords;
//
//public:
//    // Конструктор вектора размерности n
//    VectorN(unsigned int n);
//    VectorN(const vector<type>& coords);
//    VectorN():VectorN(0){};
//
//    // Деструктор
//    ~VectorN();
//
//    // Получение размерности вектора
//    unsigned getDimension() const;
//    type getValue(unsigned int i) const;
//    void setValue(unsigned int i, type value);
//
//    bool operator == (VectorN<type>& vector);
//    bool operator != (VectorN<type>& vector);
//    VectorN<type> operator + (VectorN<type>& vectorN);
//    VectorN<type> operator * (int k);
//    friend VectorN<type> operator *(int k, VectorN<type>& vectorN);
//    friend istream& operator >> (istream& in, VectorN<type>& vectorN);
//};
//
//
//template<typename type>
//VectorN<type>::VectorN(unsigned int n) {
//    this->coords.resize(n, 0);
//    this->dimension = n;
//}
//
//template<typename type>
//VectorN<type>::VectorN(const vector<type> &coords) {
//    this->coords.reserve(coords.size());
//    for (int v: coords) {
//        this->coords.push_back(v);
//    }
//    this->dimension = coords.size();
//}
//
//template<typename type>
//unsigned int VectorN<type>::getDimension() const {
//    return this->dimension;
//}
//
//template<typename type>
//type VectorN<type>::getValue(unsigned int i) const {
//    return this->coords[i];
//}
//
//template<typename type>
//void VectorN<type>::setValue(unsigned int i, type value) {
//    this->coords[i] = value;
//}
//
//template<typename type>
//bool VectorN<type>::operator==(VectorN<type>& vector) {
//    if (this->dimension != vector.dimension)
//        return false;
//    for (unsigned int i = 0; i < vector.dimension; i++)
//        if (this->coords[i] != vector.coords[i]) return false;
//    return true;
//}
//
//template<typename type>
//bool VectorN<type>::operator!=(VectorN<type>& vector) {
//    return !(*this == vector);
//}
//
//template<typename type>
//VectorN<type> VectorN<type>::operator+(VectorN<type>& vectorN) {
//    vector<type> sum_coords;
//    sum_coords.reserve(this->dimension);
//    for (unsigned int i = 0; i < vectorN.dimension; i++)
//        sum_coords.push_back((this->coords[i] + vectorN.coords[i]));
//    return VectorN(sum_coords);
//}
//
//template<typename type>
//VectorN<type> VectorN<type>::operator*(int k) {
//    vector<type> sum_coords;
//    sum_coords.reserve(this->dimension);
//    for (unsigned int i = 0; i < this->dimension; i++)
//        sum_coords.push_back(this->coords[i]*k);
//    return VectorN(sum_coords);
//}
//
//template<typename type>
//VectorN<type> operator *(int k, VectorN<type>& vectorN) {
//    vector<type> sum_coords;
//    sum_coords.reserve(vectorN.dimension);
//    for (unsigned int i = 0; i < vectorN.dimension; i++)
//        sum_coords.push_back(vectorN.coords[i]*k);
//    return VectorN<type>(sum_coords);
//}
//
//// example: {4, (5, 5, 5, 5)}
//template<typename type>
//ostream &operator << (ostream &of, VectorN<type> &vectorN) {
//    of << "{" << vectorN.getDimension() << ", (";
//    for(unsigned int i = 0; i < vectorN.getDimension() - 1; i++)
//        of << vectorN.getValue(0)<< ", ";
//    of << vectorN.getValue(vectorN.getDimension()-1) << ")" << "}";
//    return of;
//}
//
//template<typename type>
//VectorN<type>::~VectorN() = default;
