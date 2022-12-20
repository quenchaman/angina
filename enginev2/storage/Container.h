#ifndef ANGINA_STORAGE_CONTAINER_H
#define ANGINA_STORAGE_CONTAINER_H

template <typename StoredType, size_t capacity>
class Container {
public:
	Container() {}

	StoredType data[capacity];

	void push_back(const StoredType& item) {
		data[index] = item;
		++index;
	}

	size_t size() const {
		return index;
	}
private:
	size_t index = 0;
};

#endif // !ANGINA_STORAGE_CONTAINER_H
