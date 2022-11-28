#include <iostream>

template <typename T>
 class array
{
    public:
        array();
        array(unsigned int);
        ~array();
        bool operator==(const array&);
        array<T>& operator=(const array<T> &obj);
        T& operator[](unsigned int);
        void add(const T &elem);
        int size();
        
    
    private:
        T* m_array;
        int m_size;
};

template <typename T> 
array<T>::array()
    {   
        this->m_size = 0;
        m_array = new T[this->m_size];
    }

template <typename T> 
array<T>::array(unsigned int size)
{
    m_size = size;
    m_array = new T[m_size];
}

template <typename T> 
array<T>::~array()
{
    delete[] m_array;
}

template <typename T> 
array<T>& array<T>::operator=(const array<T> &obj)
{
    m_size = obj.m_size;
    if(m_size != 0){
        delete [] m_array;
        m_array  = new T[m_size];
        for(int i = 0; i < m_size; ++i){
            m_array[i] = obj.m_array[i];
        }
    }else{
        m_array = nullptr;
    }
        return *this;
}

template <typename T> 
bool array<T>::operator==(const array &my_obj)
{   
    bool result = false;
    if(this->m_size != my_obj.m_size)
        for(int i = 0; i < this->m_size; ++i){
            if(my_obj.m_array[i] == this->m_array[i]){
                result = true;
            }else{
                return result;
            }
        }
        return result;
}

template <typename T>
T& array<T>::operator[](unsigned int index)
{
    if(index < 0 || index > m_size)
        std::cout << "Warning: Bad index." << std::endl;
    return m_array[index];
}

template <typename T>
void array<T>::add(const T &elem)
{
    static int index = 0;
    if (index < this->m_size){
        this->m_array[index] = elem;
        index++;
    }else{
        std::cout << "Array is full:" << std::endl;
    }
}

template <typename T>
 int array<T>::size()
{
    return m_size;
}

int main()
{   
    array<int> arr(3);
    arr.add(5);
    arr.add(6);
    arr.add(7);

    std::cout << "arr.size :  " << arr.size() << std::endl;
    for(int i=0; i<arr.size(); ++i){
        std::cout << arr[i] << std::endl;
    }

    array<int> arr2;
    arr2 = arr;

    std::cout << arr2.size() << std::endl;
}
