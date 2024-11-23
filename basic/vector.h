#ifndef _JSTD_VECTOR
#define _JSTD_VECTOR

namespace jstd {
	template<class T>
	class vector {
		private:
			T *v;
			int sz, capacity;
		public:
			vector(int n) {
				v=new T[n*2];
				sz=n, capacity=n*2;
			}
			vector() {
				v=new T[16];
				sz=0, capacity=16;
			}
			~vector() {
				delete[] v;
				sz=0;
			}
			void add(T x) {
				if(sz==capacity) {
					T *u=new T[capacity*2];
					capacity*=2;
					for(int i=0; i<sz; i++)
						u[i]=v[i];
					delete[] v;
					v=u;
				}
				v[sz++]=x;
			}
			T operator[](int x) {
				return v[x];
			}
			T pop() {
				if(sz*2<capacity) {
					T *u=new T[capacity/2];
					capacity/=2;
					for(int i=0; i<sz; i++)
						u[i]=v[i];
					delete[] v;
					v=u;
				}
				return v[--sz];
			}
			int size() {
				return sz;
			}
			void resize(int n) {
				T *u=new T[n*2];
				capacity=n*2;
				int goal=sz<n?sz:n;
				for(int i=0; i<goal; i++)
					u[i]=v[i];
				delete[] v;
				v=u;
			}
			int max_size() {
				return capacity;
			}
			bool empty() {
				return size()==0;
			}
	};
}
#endif

