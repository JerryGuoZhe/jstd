#ifndef _JSTD_QUEUE
#define _JSTD_QUEUE
#include"deque.h"

namespace jstd {
	template<class T>
		class queue {
			private:
				jstd::deque<int>q;
			public:
				int size() {
					return q.size();
				}
				int max_size() {
					return q.max_size();
				}
				bool empty() {
					return q.empty();
				}
				void push(T x) {
					q.push_back(x);
				}
				T pop() {
					return q.pop_front();
				}	
				T front() {
					return q.front();
				}
				T back() {
					return q.back();
				}
		};
}

#endif

