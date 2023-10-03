

#ifndef LABA_ITEM_DYNAMIC_ARRAY_H
#define LABA_ITEM_DYNAMIC_ARRAY_H

#include <stdexcept>

template<typename T>
class DynamicArray {
public:
	DynamicArray();
	
	~DynamicArray();
	
	void add(const T &new_item);
	
	void remove(const int index);
	
	
	T &operator[](const int index) const;
	
	int get_size() const;

private:
	T *m_items;
	int m_capacity;
	int m_size;
	
	static constexpr int base_size = 8;
	static constexpr double coeff = 1.5;
};

template<typename T>
void DynamicArray<T>::remove(const int index) {
	if (index < 0 || index >= m_size) {
		return;
	}
	for (int i = index; i < m_size - 1; i++) {
		m_items[i] = m_items[i + 1];
	}
	m_size--;
	
	if (m_capacity > base_size && m_size < m_capacity / (coeff * coeff)) {
		m_capacity = static_cast<int>(m_capacity / coeff);
		T *new_data = new T[m_capacity];
		std::copy(m_items, m_items + m_size, new_data);
		delete[] m_items;
		m_items = new_data;
	}
}

template<typename T>
void DynamicArray<T>::add(const T &new_item) {
	if (m_size == m_capacity) {
		if (m_capacity == 0) {
			m_capacity = 1;
		} else {
			m_capacity = static_cast<int>(m_capacity * coeff);
		}
		T *new_data = new T[m_capacity];
		std::copy(m_items, m_items + m_size, new_data);
		delete[] m_items;
		m_items = new_data;
	}
	m_items[m_size++] = new_item;
}


template<typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] m_items;
	m_size = 0;
	m_capacity = 0;
}

template<typename T>
DynamicArray<T>::DynamicArray() {
	m_items = new T[base_size];
	m_capacity = base_size;
	m_size = 0;
	
	
}

template<typename T>
int DynamicArray<T>::get_size() const {
	return m_size;
}

template<typename T>
T &DynamicArray<T>::operator[](const int index) const {
	if (index < 0 || index >= m_size) {
		throw std::out_of_range("Index out of range");
	}
	return m_items[index];
}

#endif



