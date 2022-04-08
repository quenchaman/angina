#ifndef RENDERER_REPOSITORIES_REPOSITORY_H_
#define RENDERER_REPOSITORIES_REPOSITORY_H_

#include <string>
#include <unordered_map>
#include <iostream>

template <typename T>
class Cache {
public:
	void add(const std::string key, T& item) {
		data[key] = &item;
	}

	T& get(const std::string& key) {
		std::cout << "Cache hit!" << std::endl;
		return *data.at(key);
	}

	bool exists(const std::string& key) const {
		return data.find(key) != data.end();
	}

	~Cache() {
		for (auto const& [id, item] : data) {
			if (item != nullptr) {
				delete item;
			}
		}
	}
private:
	std::unordered_map<std::string, T*> data;
};

#endif /* RENDERER_REPOSITORIES_REPOSITORY_H_ */
