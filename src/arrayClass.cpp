#include "arrayClass.hpp"
#include <iostream>
#include <cassert>

array::array() 
    : m_size(0)
    , m_arr(0)
{
}

array::array(int size) 
    : m_arr(0)
{
    m_size = size;
    m_arr = new int[m_size];
    assert(m_arr);
    for (int i = 0; i < m_size; ++i) {
        m_arr[i] = 0;
    }
}

array::~array()
{
    if (m_arr != 0) {
        delete [] m_arr;
    }
    m_arr = 0;
}

array::array(const array& obj)
    : m_arr(0)
    , m_size(0)
{
    m_size = obj.m_size;
    m_arr = new int[m_size];
    for (int i = 0; i < m_size; i++) {
        m_arr[i] = obj.m_arr[i];
    }
}

array& array::operator=(const array&  obj)
{
    if (this == &obj) {
        return *this;
    }
    m_size = obj.m_size;
    m_arr = new int[m_size];
    for (int i = 0; i < m_size; i++) {
        m_arr[i] = obj.m_arr[i];
    }
    return *this;
}

int& array::operator [] (int index)
{
    if (index >= 0 && index < m_size) {
        return m_arr[index];
    } else {
        std::cout << "Error - index out of range" << std::endl;
    }
}

void array::resize(int size)
{
    int *new_arr = new int[size];
    if (size >= m_size) {
        for (int i = 0; i < m_size; i++) {
            new_arr[i] = m_arr[i];
        }
        for (int j = m_size; j < size; j++) {
            new_arr[j] = 0;
        } 
    } else {
        for (int i = 0; i < size; i++) {
            new_arr[i] = m_arr[i];
        }
    }
    m_size = size; 
    delete [] m_arr;
    m_arr = new_arr;
}

bool array::operator == (const array& obj)
{
    if (m_size != obj.m_size) {
        return false;
    }
    for (int i = 0; i < m_size; i++) {
        if (m_arr[i] != obj.m_arr[i]) {
            return false;
        }
    }
    return true;
}

void array::print_array() const
{
	for (int i = 0; i < m_size; i++) {
	    std::cout << m_arr[i] << "  ";
	}
	std::cout << std::endl;
}

int array::size() const
{
    return m_size;
}

/*void array::insert(int i, int b)
{
    for (int j = m_size; j > i; --j) {
        m_arr[j] = m_arr[j - 1];
    }
    m_arr[i] = b;
    resize(++m_size);
}*/
void array::insert(int i, int b, int k)
{
   resize(m_size + k);
    for (int j = m_size - 1 ; j >= i + k; --j) {
        m_arr[j] = m_arr[j - k];
    }
    for (int j = i; j < i + k; ++j) {
        m_arr[j] = b;
    }
} 
void array::erase(int p)
{
    for (int i = p; i < m_size; ++i) {
        m_arr[i] = m_arr[i + 1];
    }
    resize(--m_size);
}
void array::pop_back()
{
    resize(--m_size);
}
void array::push_back(int a)
{
    m_size++;
    m_arr[m_size - 1] = a;
}



