#ifndef _JSTD_HEAP
#define _JSTD_HEAP
#include"vector.h"

namespace jstd {
	template<class T, bool (*cmp)(T, T)>
		class heap {
			private:
				jstd::vector<T>v;
			public:
				heap() {}
				void push(T x) {
					v.add(x);
					int pos=v.size()-1;
					while(pos!=0) {
						if(cmp(v[pos], v[(pos+1)/2-1])) {
							T t=v[pos];
							v[pos]=v[(pos+1)/2-1], v[(pos+1)/2-1]=t;
							pos=(pos+1)/2-1;
						}
						else
							break;
					}
				}
				T pop() {
					T res=v[0];
					v[0]=v.pop();
					int pos=0;
					while(pos*2+1<v.size()) {
						if(pos*2+2>=v.size()&&cmp(v[pos*2+1], v[pos])) {
							T t=v[pos];
							v[pos]=v[pos*2+1], v[pos*2+1]=t;
							pos=pos*2+1;
						}
						else if(pos*2+2>=v.size())
							break;
						else if(pos*2+2<v.size()) {
							if(cmp(v[pos*2+1], v[pos*2+2])&&cmp(v[pos*2+1], v[pos])) {
								T t=v[pos];
								v[pos]=v[pos*2+1], v[pos*2+1]=t;
								pos=pos*2+1;
							}
							else if(!cmp(v[pos*2+1], v[pos*2+2])&&cmp(v[pos*2+2], v[pos])) {
								T t=v[pos];
								v[pos]=v[pos*2+2], v[pos*2+2]=t;
								pos=pos*2+2;
							}
							else
								break;
						}
					}
					return res;
				}
				T top() {
					return v[0];
				}
				int size() {
					return v.size();
				}
				bool empty() {
					return v.empty();
				}
		};
}

#endif

