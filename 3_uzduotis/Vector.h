#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include <cstring>
using std::size_t;

namespace custom {
	template<class T>
	class vector {
	private:
		T* elem;
		size_t sz;
		size_t cap;


		void _reallocate(size_t);
		size_t _exponentCapacity(size_t) const;
		static void _deleteRange(T*, T*);

	public:
		using value_type = T;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


		vector() : sz{ 0 }, cap{ 0 }  {elem = new T[cap]; }
		vector(int);
		vector(size_t, T);
		vector(const vector<T>&);
		vector(vector<T>&&) noexcept;
		vector(std::initializer_list<T> il);
		~vector();

		size_t size() const { return sz; }
		size_t capacity() const { return cap; }
		void setElem(int idx, T val);

		vector<T>& operator=(const vector<T>&);
		vector<T>& operator=(vector&&);
		vector<T>& operator=(std::initializer_list<T>);

		template<typename Y>
		friend vector<Y> operator+(const vector<Y>&, const vector<Y>&);

		template<typename Y>
		friend vector<Y> operator-(const vector<Y>&, const vector<Y>&);

		bool operator==(const vector<T>&);
		bool operator!=(const vector<T>&);
		bool operator>(const vector<T>&);
		bool operator<(const vector<T>&);

		reference at(size_t);
		const_reference at(size_t) const;

		reference operator[](size_t);
		const_reference operator[](size_t) const;

		reference front();
		const_reference front() const;

		reference back();
		const_reference back() const;

		T* data() noexcept;
		const T* data() const noexcept;

		iterator begin() noexcept;
		const_iterator begin() const noexcept;
		const_iterator cbegin() const noexcept;

		iterator end() noexcept;
		const_iterator end() const noexcept;
		const_iterator cend() const noexcept;

		reverse_iterator rbegin() noexcept;
		const_reverse_iterator rbegin() const noexcept;

		reverse_iterator rend() noexcept;
		const_reverse_iterator rend() const noexcept;



		void clear();
		void reserve(size_t);
		void resize(size_t);
		bool empty() const;
		void shrink_to_fit();
		//bool empty() const noexcept;
		void swap(vector<T>&);

		void push_back(const T&);
		void push_back(T&&);
		template<class ... Args> void emplace_back(Args&& ... args);
		void pop_back();
		size_t max_size() const;



	};


	//template<class T>
	//void swap(T& a, T& b) {
	//	T temp{ std::move(a) };
	//	a = std::move(b);
	//	b = std::move(temp);
	//}

	template<class T>
	vector<T>::vector(const vector<T>& v) : elem{ new T[v.sz] }, sz{ v.sz }, cap{ v.cap }	{
		//for (size_t i = 0; i != sz; ++i) elem[i] = v.elem[i];
		std::cout << "vec::copy::constr" << std::endl;
		std::copy(v.elem, v.elem + v.sz, elem);
	}



	template<class T>
	vector<T>::vector(vector<T>&& v) noexcept : elem{ nullptr }, sz{ 0 }, cap{ 0 }
	{
		std::cout << "vec::move::constr" << std::endl;
		v.swap(*this);
	}




	template<class T>
	vector<T>::vector(std::initializer_list<T> il)
		: elem{ new T[il.size()] },
		sz{ static_cast<size_t>(il.size()) },
		cap{ static_cast<size_t>(il.size()) }
	{
		std::cout << "vec::init::list" << std::endl;
		std::copy(il.begin(), il.end(), elem);
	}



	template<class T>
	vector<T>::~vector() {
		if (elem == nullptr) return;
		_deleteRange(elem, elem + sz);
		delete[] elem;
	}



	template<class T>
	vector<T>::vector(int s) : elem{ new T[s] }, sz{ s }, cap{ s } {
		for (int i = 0; i < sz; ++i)
			elem[i] = T();
	}



	template<class T>
	vector<T>::vector(size_t s, T val) : elem{ new T[s] }, sz{ s }, cap{ s }  {
		std::fill_n(elem, s, val);
	}



	template<class T>
	void vector<T>::setElem(int idx, T val) {
		if (idx < 0 || idx >= sz) return;
		elem[idx] = val;
	}



	template<class T>
	vector<T>& vector<T>::operator=(const vector<T> & v) {
		if (&v == this) return *this;
		sz = v.size();
		cap = v.capacity();
		elem = new T[cap];

		for (size_t i = 0; i != sz; ++i) {
			elem[i] = v.elem[i];
		}
		return *this;
	}
	template<class T>
	vector<T>& vector<T>::operator=(vector<T> && v) {
		v.swap(*this);
		return *this;
	}





	template<class T>
	vector<T> operator+(const vector<T> & a, const vector<T> & b) {
		if (a.size() != b.size())
			throw std::runtime_error("vector dydziu neatitikimas");
		auto size = a.size();
		vector<T> c(size);
		for (auto i = 0; i != a.size(); ++i)
			c[i] = a[i] + b[i];
		return c;

	}
	template<class T>
	vector<T> operator-(const vector<T> & a, const vector<T> & b) {
		if (a.size() != b.size())
			throw std::runtime_error("vector dydziu neatitikimas");
		size_t size = a.size();
		vector<T> c(size);
		for (size_t i = 0; i != a.size(); ++i)
			c[i] = a[i] - b[i];
		return c;

	}
	template<class T>
	bool vector<T>::operator==(const vector<T> & v) {
		if (sz == v.size()) {
			for (int i = 0; i != sz; ++i) {
				if (elem[i] != v[i]) return false;
				return true;
			}
		}
		return false;
	}
	template<class T>
	bool vector<T>::operator!=(const vector<T> & v) {
		return !operator==(v);
	}


	template<class T>
	inline vector<T>& vector<T>::operator=(std::initializer_list<T> il)
	{
		T* temp = new T[il.size()];
		std::copy(il.begin(), il.end(), temp);
		delete[] elem;
		elem = temp;
		sz = il.size();
		cap = il.size();
		return *this;
	}

	template<class T>
	bool vector<T>::operator>(const vector<T> & v) {
		if (elem == v.elem && sz == v.size()) return false;


		auto min_siz = sz < v.size() ? sz : v.size();
		for (int i = 0; i != min_siz; ++i) {
			if (elem[i] == v.elem[i]) continue;
			return elem[i] > v.elem[i] ? true : false;

		}
		return min_siz == sz ? false : true; // if equal but one's size is greater
	}

	template<class T>
	bool vector<T>::operator<(const vector & v) {
		if (elem == v.elem && sz == v.size()) return false;

		auto min_siz = sz < v.size() ? sz : v.size();
		for (int i = 0; i != min_siz; ++i) {
			if (elem[i] == v.elem[i]) continue;
			return elem[i] < v.elem[i] ? true : false;

		}
		return min_siz == sz ? true : false; // if equal but one's size is greater
	}


	template<class T>
	typename vector<T>::reference vector<T>::at(size_t pos) {
		if (pos < sz) {
			return elem[pos];
		}

		throw std::out_of_range("out of range");
	}

	template<typename T>
	typename vector<T>::const_reference vector<T>::at(size_t pos) const {
		return at(pos);
	}

	template<class T>
	typename vector<T>::reference vector<T>::operator[](size_t pos) {
		return elem[pos];
	}

	template<class T>
	typename vector<T>::const_reference vector<T>::operator[](size_t pos) const {
		return elem[pos];
	}

	template<class T>
	typename vector<T>::reference vector<T>::front() {
		return elem[0];
	}

	template<class T>
	typename vector<T>::const_reference vector<T>::front() const {
		return elem[0];
	}

	template<class T>
	typename vector<T>::reference vector<T>::back() {
		return elem[sz - 1];
	}

	template<class T>
	typename vector<T>::const_reference vector<T>::back() const {
		return elem[sz - 1];
	}

	template<class T>
	T* vector<T>::data() noexcept {
		return elem;
	}
	template<class T>
	const T* vector<T>::data() const noexcept {
		return elem;
	}

	template<class T>
	typename vector<T>::iterator vector<T>::begin() noexcept {
		return elem;
	}

	template<class T>
	typename vector<T>::const_iterator vector<T>::begin() const noexcept {
		return elem;
	}

	template<class T>
	typename vector<T>::const_iterator vector<T>::cbegin() const noexcept {
		return begin();
	}

	template<class T>
	typename vector<T>::iterator vector<T>::end() noexcept {
		return elem + sz;
	}

	template<class T>
	typename vector<T>::const_iterator vector<T>::end() const noexcept {
		return elem + sz;
	}

	template<class T>
	typename vector<T>::const_iterator vector<T>::cend() const noexcept {
		return end();
	}

	template<class T>
	typename vector<T>::reverse_iterator vector<T>::rbegin() noexcept {
		return reverse_iterator(elem + sz);
	}

	template<class T>
	typename vector<T>::const_reverse_iterator vector<T>::rbegin() const noexcept {
		return rbegin();
	}

	template<class T>
	typename vector<T>::reverse_iterator vector<T>::rend() noexcept {
		return reverse_iterator(elem);
	}

	template<class T>
	typename vector<T>::const_reverse_iterator vector<T>::rend() const noexcept {
		return rend();
	}




	template<class T>
	void vector<T>::clear() {
		for (size_t i = 0; i < sz; ++i)
			elem[i].~T();
		sz = 0;
	}

	template<class T>
	void vector<T>::reserve(size_t mem) {
		if (mem <= cap) return;
		if (cap > max_size()) {
			throw new std::length_error("max length exceeded");
		}
		cap = mem;
		//_reallocate();
	}
	template<class T>
	inline void vector<T>::resize(size_t s)
	{
		if (s < sz) {
			for (size_t i = s; i < sz; ++i)
				elem[i].~T();
		}
		else if (s > sz) {
			if (s > cap) {
				cap = s;
				_reallocate(cap);
			}
			for (size_t i = sz; i < s; ++i) {
				elem[i] = T();
			}
		}
		sz = s;


	}
	template<class T>
	inline bool vector<T>::empty() const
	{
		return sz == 0;
	}

	template<class T>
	void vector<T>::shrink_to_fit() {
		for (auto i = sz; i < cap; i++) {
			elem[i].~T();
		}
		cap = sz;
	}


	template<class T>
	inline void vector<T>::swap(vector<T> & other)
	{
		size_t tSz, tCap;
		T* tElem;

		tElem = other.elem;
		tSz = other.sz;
		tCap = other.cap;

		other.elem = elem;
		other.sz = sz;
		other.cap = cap;

		sz = tSz;
		cap = tCap;
		elem = tElem;
	}
	template<class T>
	void vector<T>::push_back(const T & val) {

		if (sz == cap) {
			_reallocate(cap + 1);
		}

		elem[sz] = val;
		++sz;
	}

	template<class T>
	inline void vector<T>::push_back(T && val)
	{
		if (sz == cap) {
			_reallocate(cap + 1);
		}

		elem[sz] = std::move(val);
		++sz;
	}
	template<class T>
	template<class ... Args>
	inline void vector<T>::emplace_back(Args && ... args)
	{
		if (sz == cap) {
			_reallocate(cap + 1);
		}
		elem[sz] = std::move(T(std::forward<Args>(args)...));
		++sz;
	}

	template<class T>
	inline void vector<T>::pop_back()
	{
		--sz;
		elem[sz].~T();
	}

	template<class T>
	size_t vector<T>::max_size() const {
		return std::numeric_limits<size_t>::max();
	}



	template<class T>
	size_t vector<T>::_exponentCapacity(size_t size) const {
		if (capacity() > max_size() - capacity() / 2) {
			return size;
		}

		const size_t multiple = cap * 1.5;

		if (multiple < size) {
			return size;
		}
		return multiple;
	}

	template<class T>
	inline void vector<T>::_deleteRange(T * begin, T * end)
	{
		while (begin != end)
		{
			begin->~T();
			++begin;
		}
	}


	template<typename T>
	inline void vector<T>::_reallocate(size_t min) //recreates vector to use new capacity
	{
		const size_t newCap = _exponentCapacity(min);
		T* temp = new T[newCap];
		for (size_t i = 0; i < sz; ++i) {
			temp[i] = elem[i];
		}
		delete[] elem;
		elem = temp;
		cap = newCap;
	}

}



class Mock {
public:
	int a;
	double b;

	Mock() : a{ 0 }, b{ 0 } {}
	Mock(int a_, double b_) : a{ std::move(a_) }, b{ std::move(b_) }	{
		std::cout << "I am being constructed.\n";
	}

	Mock(Mock&& other) noexcept : a{ std::move(other.a) }, b{ std::move(other.b) }	{
		std::cout << "I am being moved.\n";
	}

	Mock& operator=(const Mock& other) = default;
};