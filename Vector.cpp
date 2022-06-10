#include "Vector.h"
#include <iostream>
#include <cassert>
#include <cmath>

Vector::Vector(int a) {
    if (a >= 2) {
        m_c = a;

    }
    else {
        m_c = 2;
    }
    m_p = new double[m_c];
    for (int i = 0; i < a; i++) {
        m_p[i] = 0;
    }
}

Vector::Vector(double* k, int a) {
    if (a >= 2) {
        m_c = a;
    }
    else {
        Vector();
    }
    m_p = new double[m_c];
    for (int i = 0; i < a; i++) {
        m_p[i] = k[i];
    }
}

Vector::Vector(const Vector& a) {
    m_c = a.m_c;
    m_p = new double[m_c];
    for (int i = 0; i < m_c; i++) {
        m_p[i] = a.m_p[i];
    }

}

Vector::~Vector() {
    delete[] m_p;
}

Vector& Vector::operator=(const Vector& a) {
    if (this != &a) {
        if (m_c != a.m_c) {
            delete[] m_p;
            m_c = a.m_c;
            m_p = new double[m_c];
        }
        for (int i = 0; i < m_c; i++) {
            m_p[i] = a.m_p[i];
        }
    }
    return *this;
}

double Vector::operator[] (int n)const {
    assert(n >= 0 && n < m_c);
    return m_p[n];
}

double& Vector::operator[](int n) {
    assert(n >= 0 && n < m_c);
    return m_p[n];
}

std::istream& operator>>(std::istream& in, Vector& a) {
    std::cout << "count = ";
    in >> a.m_c;
    std::cout << "elem = ";
    a.m_p = new double[a.m_c];
    for (int i = 0; i < a.m_c; i++) {
        in >> a.m_p[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, Vector& a) {
    out << "the elements are = ";
    for (int i = 0; i < a.m_c; i++) {
        out << a.m_p[i] << " ";
    }
    out << std::endl;
    return out;
}

bool Vector::operator<(Vector& a) {
    int t = 1;
    if (m_c > a.m_c)t = 1;
    else t = 0;
    for (int i = 0; i < m_c; i++) {
        if (m_p[i] < a.m_p[i])
            return true;
    }
    if (!t)return true;
    return false;
}

bool Vector::operator>(Vector& a) {
    int t = 1;
    if (m_c > a.m_c)t = 1;
    else t = 0;
    for (int i = 0; i < m_c; i++) {
        if (m_p[i] > a.m_p[i])
            return true;
    }
    if (t)return true;
    return false;
}

bool Vector::operator>=(Vector& a) {
    int t = 1;
    if (m_c > a.m_c)t = 1;
    else t = 0;
    for (int i = 0; i < m_c; i++) {
        if (m_p[i] >= a.m_p[i])
            return true;
    }
    if (t)return true;
    return false;
}

bool Vector::operator<=(Vector& a) {
    int t = 1;
    if (m_c > a.m_c)t = 1;
    else t = 0;
    for (int i = 0; i < m_c; i++) {
        if (m_p[i] <= a.m_p[i])
            return true;
    }
    if (!t)return true;
    return false;
}

Vector Vector::operator+(const Vector& a)const {
    Vector l;

    if (m_c > a.m_c) {
        l.m_c = m_c;

    }
    else l.m_c = a.m_c;
    l.m_p = new double[l.m_c];
    for (int i = 0; i < m_c && i < a.m_c; i++) {
        l.m_p[i] = m_p[i] + a.m_p[i];
    }

    for (int i = a.m_c; i < m_c; i++) {
        l.m_p[i] = m_p[i];
    }
    for (int i = m_c; i < a.m_c; i++) {
        l.m_p[i] = a.m_p[i];
    }

    return l;
}

Vector Vector::operator-(const Vector& a)const {
    Vector l;

    if (m_c > a.m_c) {
        l.m_c = m_c;

    }
    else l.m_c = a.m_c;
    l.m_p = new double[l.m_c];
    for (int i = 0; i < m_c && i < a.m_c; i++) {
        l.m_p[i] = m_p[i] - a.m_p[i];
    }
    for (int i = a.m_c; i < m_c; i++) {
        l.m_p[i] = m_p[i];
    }
    for (int i = m_c; i < a.m_c; i++) {
        l.m_p[i] = a.m_p[i];
    }

    return l;
}


Vector& Vector::operator+=(Vector& a) {
    *this = *this + a;
    return *this;
}

Vector& Vector::operator-=(Vector& a) {
    *this = *this - a;
    return *this;
}

int Vector::operator*(const Vector& obj)const
{
    int min_size;
    if (m_c < obj.m_c)
    {
        min_size = m_c;
    }
    else
    {
        min_size = obj.m_c;
    }
    int sum = 0;
    for (int i = 0; i < min_size; i++)
    {
        sum += (m_p[i] * obj.m_p[i]);
    }
    return sum;
}
