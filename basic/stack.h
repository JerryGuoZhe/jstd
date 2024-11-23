#ifndef _JSTD_STACK
#define _JSTD_STACK

#include"vector.h"
namespace jstd {
	template<class T>
		class stack {
			private:
				jstd::vector<T>v;
			public:
				void push(T x) {
					v.add(x);
				}
				T pop() {
					return v.pop();
				}
				int size() {
					return v.size();
				}
				T top() {
					return v[v.length()-1];
				}
				bool empty() {
					return v.empty();
				}
		};
}

#endif

