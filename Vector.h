#pragma once

class Vector {
private:
    double* m_p;
    int m_c;
public:
    Vector(int = 2);
    Vector(double*, int);
    Vector(const Vector&);
    ~Vector();
    Vector& operator=(const Vector&);
    double operator[](int) const;
    double& operator[](int);
    friend std::istream& operator>>(std::istream&, Vector&);
    friend std::ostream& operator<<(std::ostream&, Vector&);
    bool operator<(Vector&);
    bool operator>(Vector&);
    bool operator>=(Vector&);
    bool operator<=(Vector&);
    Vector operator+(const Vector&)const;
    Vector operator-(const Vector&)const;
    Vector& operator+=(Vector&);
    Vector& operator-=(Vector&);
    int operator*(const Vector&) const;
    double dis_(Vector&);

};
