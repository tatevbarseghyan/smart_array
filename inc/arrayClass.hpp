
class array
{
    private:
        int m_size;
        int * m_arr;
    public:
        array();
        array(int size);
        ~array();
        array(const array& obj);
        array& operator=(const array& obj);
        int& operator [] (int index);
        void resize(int size);
        bool operator == (const array& obj);
        void print_array() const;
        int size() const;
        void insert(int p, int a, int k);
        void erase(int p);
        void push_back(int);
        void pop_back();
};
