#ifndef _JSTD_DEQUE
#define _JSTD_DEQUE

namespace jstd {
	template<class T>
		class deque {
			private:
				T *q;
				int sz, capacity;
				int fnt, rear;
				void shrink() {
					if(fnt*2<capacity) {
						T *u=new T[capacity/2];
						capacity/=2;
						for(int i=rear; i<fnt; i++)
							u[i]=q[i];
						delete[] q;
						q=u;
					}
					if(rear*2>capacity) {
						T *u=new T[capacity/2];
						capacity/=2;
						for(int i=rear; i<fnt; i++)
							u[i-capacity]=q[i];
						fnt-=capacity, rear-=capacity;
						delete[] q;
						q=u;
					}
				}
			public:
				deque() {
					q=new T[16];
					capacity=16;
					sz=0;
					fnt=8, rear=8;
				}
				~deque() {
					delete[] q;
					sz=capacity=fnt=rear=0;
				}
				void push_front(T x) {
					if(fnt==capacity) {
						T *u=new T[capacity*2];
						capacity*=2;
						for(int i=rear; i<fnt; i++)
							u[i]=q[i];
						delete[] q;
						q=u;
					}
					q[fnt++]=x;
					++sz;
				}
				void push_back(T x)	{
					if(rear==0) {
						T *u=new T[capacity*2];
						for(int i=rear; i<fnt; i++)
							u[i+capacity]=q[i];
						fnt+=capacity, rear+=capacity;
						delete[] q;
						q=u;
						capacity*=2;
					}
					q[--rear]=x;
					++sz;
				}
				T pop_front() {
					shrink();
					--sz;
					return q[--fnt];
				}
				T pop_back() {
					shrink();
					--sz;
					return q[rear++];
				}
				T front() {
					return q[fnt-1];
				}
				T back() {
					return q[rear];
				}
				int size() {
					return sz;
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

