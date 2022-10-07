#include<iostream>
using namespace std;
template<typename DT>

class List //定义双链表的类结构
{
    private:
         struct Node //设置节点的初始化函数
    {
            //每个节点都有三个变量
            DT data;
            Node *prev; //指向前一位节点的指针
            Node *next; //指向后一位节点的指针
             
            Node(const DT & d = DT{},Node*p=nullptr,Node*n=nullptr)
                                                    //将DT默认为空，而指针默认为空指针
             :data{d},prev{p},next{n}{}
                                                    //分别赋值d,p,n给予三个成员变量
            Node(DT&&d,Node*p=nullptr,Node*n=nullptr)
             :data{std::move(d)},prev{p},next{n}{}  //强制将左值给予右值引用
    };
    
    public:
        class const_iterator //const迭代器和非const迭代器的实现，用作对于数据的保护
    {
            public:
                const_iterator(): current {nullptr}
                {}
                
                const DT & operator*()const
                {return retrieve();}
                
                const_iterator & operator++() //重载操作符
                {
                    current = current->next; //将current指针指向当前位置的后一位置
                    return *this;
                }
                
                const_iterator operator++(int)
                {
                    const_iterator old = *this;
                    ++(*this);
                    return old;
                }
        
                bool operator==(const const_iterator & rhs) const
                                                            //判断操作符==的重载函数
                {return current == rhs.current;}
                bool operator != (const const_iterator & rhs)const
                                                            //判断操作符！=的重载函数
                {return !(*this == rhs);}
        
            protected:
                Node *current;
        
                DT & retrieve() const
                {return current->data;}
        
                const_iterator(Node *p):current{p} //将current指针初始化为迭代器p的函数
                {}
        
                friend class List<DT>;
    };
    
        class iterator : public const_iterator //定义迭代器的类
    {
            public:
                iterator()
                {}
                
                DT & operator* ()
                {return const_iterator::retrieve();}
                const DT & operator*() const
                {return const_iterator::operator*();}
                
                iterator & operator++()
                {
                    this->current = this->current->next;
                    return *this;
                }
        
                iterator operator++(int)
                {
                    iterator old = *this;
                    ++(*this);
                    return old;
                }
        
            protected:
                iterator(Node *p):const_iterator{p}
                {}
        
                friend class List<DT>;
    };
    
    public: //构造函数和析构函数，由于init属于private成员，因此不在public里
        List()
            {init();}
    
        ~List() //通过调用 delete显式销毁对象，释放内存空间
        {
            clear();
            delete head;
            delete tail;
        }
    
        List(const List & rhs) //重载操作符
        {
            init();
            for(auto & x:rhs)
                push_back(x);
        }
    
        List & operator=(const List &rhs)
        {
            List copy=rhs;
            std::swap(*this,copy);
            return *this;
        }
    
        List(List && rhs)
            :theSize{rhs.theSize},head{rhs.head},tail{rhs.tail}
        {
            rhs.theSize=0;
            rhs.head=nullptr;
            rhs.tail=nullptr;
        }
    
        List & operator=(List&&rhs)
        {
            std::swap(theSize,rhs.theSize);
            std::swap(head,rhs.head);
            std::swap(tail,rhs.tail);
            
            return *this;
        }
   
        iterator begin( )
          { return { head->next }; }
        const_iterator begin( ) const
          { return { head->next }; }
        iterator end( )
          { return { tail }; }
        const_iterator end( ) const
          { return { tail }; }
    
        int size( ) const
          { return theSize; }
        bool empty( ) const
          { return size( ) == 0; }
    
        void clear( )
        {
            while( !empty( ) )
                pop_front( );
        }

        DT & front( ) //调取头节点的下一个节点
            { return *begin( ); }
        const DT & front( ) const
            { return *begin( ); }
        DT & back( ) //调取尾节点的上一个节点
            { return *--end( ); }
        const DT & back( ) const
            { return *--end( ); }
        void push_front( const DT & x ) //在节点的头部增加新的元素
            { insert( begin( ), x ); }
        void push_front( DT && x )
            { insert( begin( ), std::move( x ) ); }
        void push_back( const DT & x) //在节点的尾部增加新的元素
            { insert( end( ), x ); }
        void push_back( DT && x )
            { insert( end( ), std::move(x));}
        void pop_front( )
            { erase( begin( ));}
        void pop_back( )
            { erase( --end( ));}

        //Insert x before itr.
        iterator insert( iterator itr,const DT & x )
           {
            Node *p = itr.current;
            theSize++;
            return { p->prev = p->prev->next = new Node{ x, p->prev, p } };
           }
    
        //Insert x before itr.
        iterator insert( iterator itr,DT && x)
           {
            Node *p = itr.current;
            theSize++;
            return { p->prev = p->prev->next
                                    = new Node{ std::move( x ), p->prev, p } };
           }
    
        //Erase item at itr.
        iterator erase( iterator itr ) //删除itr迭代器位置上的节点
           {
            Node *p = itr.current;
            iterator retVal{ p->next };
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            theSize--;
                  
            return retVal; //返回被删除的迭代器
           }
    
        iterator erase( iterator from,iterator to)
                                        //删除某些元素，从指定的from逐个删至指定位置to
           {
            for( iterator itr = from; itr != to; )
               itr = erase( itr );
           return to;
           }
                    
    private:
        int   theSize; //定义双链表长度，以保存该数值
        Node *head; //定义头节点
        Node *tail; //定义尾节点
    
        void init() //初始化各项变量
        {
            theSize=0;
            head = new Node;
            tail = new Node;
            head->next = tail;
            tail->prev = head;
        }
};
