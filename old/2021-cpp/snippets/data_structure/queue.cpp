// 210811-1728

#define Q_SZ 1001
template <typename T>
class queue {
    T _q[Q_SZ];
    int _front, _rear;
    //int _sz;
public:
    queue() {
        _front = _rear = 0;
        //_sz = 0;
    }
    void push(T e) {
        T tmp;
        if ((tmp = (_rear + 1) % Q_SZ) != _front) {
            _q[_rear] = e, _rear = tmp;
        }
    }
    void pop() {
        if (_front != _rear)
            _front = (_front + 1) % Q_SZ;
    }
    T front() {
       return _q[_front];
    }
    /*T rear() {
        return _q[(_rear + (Q_SZ - 1)) % Q_SZ];
    }*/
    bool empty() {
        return _front == _rear;
    }
    /*int size() {
        return _sz;
    }*/
};