#ifndef _JSTD_VECTOR
#define _JSTD_VECTOR

namespace jstd {
	template<class T>
	class vector {
		private:
			T *v;
			int size, max_size;
		public:
			vector(int n) {
				v=new T[n*2];
				size=n, max_size=n*2;
			}
			vector() {
				v=new T[16];
				size=0, max_size=16;
			}
			~vector() {
				delete[] v;
				size=0;
			}
			void add(T x) {
				if(size==max_size) {
					T *u=new T[max_size*2];
					max_size*=2;
					for(int i=0; i<size; i++)
						u[i]=v[i];
					delete[] v;
					v=u;
				}
				v[size++]=x;
			}
			T operator[](int x) {
				return v[x];
			}
			T pop() {
				if(size*2<max_size) {
					T *u=new T[max_size/2];
					max_size/=2;
					for(int i=0; i<size; i++)
						u[i]=v[i];
					delete[] v;
					v=u;
				}
				return v[--size];
			}
			int length() {
				return size;
			}
			void resize(int n) {
				T *u=new T[n*2];
				max_size=n*2;
				int goal=size<n?size:n;
				for(int i=0; i<goal; i++)
					u[i]=v[i];
				delete[] v;
				v=u;
			}
	};
}
#endif

