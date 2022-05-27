#include <iostream>
using namespace std;

template<typename T1,typename T2>
class base {
protected:
     T1 value1;
     T2 value2;
public:
    base(T1 value1, T2 value2) {
        this->value1 = value1;
        this->value2 = value2;
    }
    base() :base(0, 0) {};
    void setValue1(T1 value1) { this->value1 = value1; }
    void setValue2(T2 value2){ this->value2 = value2; }
    T1 getValue1() { return this->value1; }
    T2 getValue2(){ return this->value2; }
    virtual ~base() = default;
    virtual void Print() = 0;
};

template<typename T4, typename T3, typename T1, typename T2>
class child :virtual public base<T1,T2> {
protected:
    T3 value3;
    T4 value4;
public:
    child (T3 value3, T4 value4,T1 value1,T2 value2) {
        this->value3 = value3;
        this->value4 = value4;
        this->setValue1(value1);
        this->setValue2(value2);
    }
    child() :child(0,0,0,0) {};
    void setValue3(T3 value3) { this->value3 = value3; }
    void setValue4(T4 value4) { this->value4 = value4; }
    T3 getValue3() { return this->value3; }
    T4 getValue4() { return this->value4; }
   ~child() = default;
   void Print()override {
       cout << this->value3 << " " << this->value4 <<
           " " << this->value1 << " " << this->value2 << endl;
   }
};
template<typename T4, typename T3, typename T1, typename T2,
    typename T5, typename T6>
class child2 :public child<T4,T3,T2,T1> {
    protected:
    T5 value5;
    T6 value6;
   public:
    child2(T5 value5, T6 value6) {
        this->value5 = value5;
        this->value6 = value6;
    }
    void setValue5(T5 value5) { this->value5 = value5; }
    void setValue6(T6 value6) { this->value6 = value6; }
    T5 getValue5() { return this->value5; }
    T6 getValue6() { return this->value6; }
    void Ini(T3 value3, T4 value4, T5 value, T6 value6) {
        this->setValue3(value3);
        this->setValue4(value4);
        this->setValue5(value5);
        this->setValue6(value6);
    }
    void Print() {
        cout << this->value5 << " " << this->value6 << " " << " "
            << this->getValue4() << "  " << this->getValue3() <<endl;
    }
    child2() :child2(0, 0) {};
    ~child2() = default;
};

int main()
{
    
    child<int, int,int,int> ch(1,2,3,4);
    ch.Print();
    child2<int, int,int,int,int,int> ch2(1, 2);
    ch2.Print();
    return 0;
  
}

