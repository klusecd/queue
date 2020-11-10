#pragma once

const int MAX_SIZE = 1000;

template<class T>
class Vector
{
protected:
	T* data;
	size_t size;
	size_t capacity;
	
public:
	Vector()
	{
		data = nullptr;
		size = 0;
		capacity = 0;
	}

	~Vector()
	{
		if (data) {
			delete[]data;
			data = nullptr;
		}
	}

	Vector(int n)
	{
		if ((n < 0) || (n > MAX_SIZE)) throw std::logic_error("Invalid size");
		else {
			size = n;
			capacity = n;
			data = new T[n];
			for (int i = 0; i < n; i++)
				data[i] = 0;
		}
	}

	Vector(int n, T* arr)
	{
		size = n;
		capacity = n;
		data = new T[size];
		for (size_t i = 0; i < size; i++)
			data[i] = arr[i];
	}

	Vector(const Vector& v) {
		size = v.size;
		capacity = v.capacity;
		T* data = new T[size];
		for (size_t i = 0; i < size; i++)
			data[i] = v.data[i];
	}

	void push_back(T elem)
	{
		if (size == MAX_SIZE) throw std::logic_error("Impossible to push back");
		if (size == capacity)
		{
			capacity *= 2.0;
			T *a = new int[capacity];
			memmove(a, data, sizeof(*data) * size);
			delete[] data;
			data = a;
		}
		data[size++] = elem;
	}

	void pop_back() {
		size--;
	}

	void resize(int capacity_)
	{
		T* a = new T[capacity_];
		if (size >= capacity_)
		{
			for (size_t i = 0; i < capacity_; i++)
				a[i] = data[i];
			size = capacity_;
		}
		else
		{
			for (size_t i = 0; i < size; i++)
				a[i] = data[i];
		}
		delete[] data;
		capacity = capacity_;
		data = a;
	}

	void insert(T Elem, int index)
	{
		push_back(data[size - 1]);
		for (int i = size - 1; i > index; i--)
			data[i] = data[i - 1];
		data[index] = elem;
	}

	void erase(int index)
	{
		for (int i = index; i < size; i++)
			data[i] = data[i + 1];
		size--;
	}

	void push_front(T elem) {
		insert(elem, 0);
	}

	void pop_front() {
		erase(0);
	}

	T& operator[](int index)
	{
		return this->data[index];
	}
	T operator[](int index)const
	{
		return this->data[index];
	}

};

template <class T>
class TQueue : protected Vector<T>
{
protected:
	size_t head;
public:

	TQueue() :Vector() { head = 0; }

	TQueue(size_t n) : Vector(n) { head = 0; }

	T front() { return data[head]; }

	T back() { return data[capacity-size-1]; }

	bool empty() const { return (!size); }

	bool full() const { return size == capacity; }

	void push(const T elem) {
		if (full()) {
			resize(size_t(2.0 * capacity) + 1);
			if (head) {
				T* temp = new T[capacity];
				for (size_t i = 0; i < size - head; i++)
					temp[i] = data[i + head];
				for (size_t i = size - head; i < size; i++)
					temp[i] = data[i + head - size];
				delete[] data;
				data = temp;
				head = 0;
			}
		}
		if (capacity - size == 1) {
			capacity = size++;
			data[capacity - size - 1] = elem;
		}
		else data[capacity - size] = elem;
		size++;
	};

	void pop() {
		if (empty()) throw "Queue is empty";
		if (head == capacity - 1) {
			head = 0;
		}
		else head++;
		size--;
	};

	size_t Size() { return size; }
};