#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>

template <typename C, typename T>
void insert_sorted(C &v, const T &item) {
	const auto insert_pos (lower_bound(begin(v), end(v), item));
	v.insert(insert_pos, item);
}

int main(void) {
	std::vector<std::string> v{"some", "random", "words", "without", "order", "aaa", "yyy"};

	assert(false == is_sorted(begin(v), end(v)));
	sort(begin(v), end(v));
	assert(true == is_sorted(begin(v), end(v)));

	insert_sorted(v, "foobar");
	insert_sorted(v, "zzz");

	for (const auto &w : v) {
		std::cout << w << " ";
	}
	std::cout << '\n';

	return 0;
}
