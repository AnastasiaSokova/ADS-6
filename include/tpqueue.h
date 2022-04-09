// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  private:
    T arr[size];
    int first;  
    int last;   
public:
    TPQueue() :first(0), last(0) { }
    void push(T x) {
        if (last - first >= size) {
            throw std::string("Full!");
        } else {
            for (int i = last; i >= first; --i) {
                if (x.prior > arr[(i - 1) % size].prior && i > first) {
                    arr[i % size] = arr[(i - 1) % size];
                } else {
                    arr[i % size] = x;
                    break;
                }
            }
        }           
    }
    T pop() {
        return arr[(first++) % size];
    }
    int getSize() {
        return (last - first);
    }
    T front() {
        return arr[first % size];
    }
    T back() {
        return arr[(last - 1) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
