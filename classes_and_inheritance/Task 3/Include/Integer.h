#ifndef HOMEWORK_C___INTEGER_H
#define HOMEWORK_C___INTEGER_H


class Integer {
protected:
    unsigned int* m_arr;
    int m_size;
public:
    Integer();
    Integer(int size);
    Integer(int size, const unsigned int* arr);
    
    Integer(const Integer& ob);
    
    Integer& operator=(const Integer& ob);
    virtual ~Integer();

    unsigned int &operator[](int i);
    const unsigned int &operator[](int i) const;
    int get_size() const;
    void set_size(int size);

    virtual void sum(const Integer* ob, Integer* res) = 0;
    virtual void sub(const Integer* ob, Integer* res) = 0;
    virtual void mul(const Integer* ob, Integer* res) = 0;
    virtual void div(const Integer* ob, Integer* res) = 0;

    virtual void get_number() = 0;
    virtual void set_number() = 0;
};


#endif //HOMEWORK_C___INTEGER_H
