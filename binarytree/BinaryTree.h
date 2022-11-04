#include<iostream>
#inlcude<fstream>
#include<string.h>
usingnamespace std;

class ArrayTree<DT> 
{
    private:
      DT[] data;
      const int deep;
      const int maxSize;
      const int size=0;
 
      ArrayTree(const int deep);
 
      createRoot(TD value);
}

class ArrayTreemodifydata<DT> 
{
    public:
      void add(DT value ,const int index,boolean left);
        //如果不是完全二叉树  会浪费一定存储空间
 
    //根据根节点是否为空判断二叉树是否为空
      boolean isEmpty();
 
    //打印二叉树 注意此时用maxSize,不是元素个数
      const int size()
      {
        return size;
      }
}

class ArrayTreetest<DT> 
{
    //test
    public:
       static void main(const String args[]);
}

class LinkedTree<DT> 
{
    public:
        class Node<DT> 
        {
            public :
              Node left;
              Node right;
              DT data;
 
        //节点构造函数
              Node(DT data) 
              this.data = data;
              this.left = null;
              this.right = null;
        }
 
    private:
        Node root=null;
        const int size;

    public :
        void createRoot(DT value);
        void Node add(Node<DT>parent,DT data,boolean left)
        
        const int size()
        {
        return size;
        }
}

class traversalTree<DT> 
{
//前序遍历  
    public:
        List<Node> preOrder();
 
    private:
        List<Node> preOrder(Node n);
 
 //中序遍历
    public: 
        List<Node>midOrder();
 
    private:
        List<Node>midOrder(Node n)
          {
              List<Node>list=new ArrayList<Node>();
              if(n.left!=null)
              {
                  list.addAll(midIterator(n.left));
              }
              
              list.add(n);
         
              if (n.right!=null)
              {
                list.addAll(midIterator(n.right));
              }
          
              return list;
          }
 
 //后序遍历
    public:
        List<Node>afterOrder();
 
    private:
        List<Node>afterOrder(Node n)
        {
            List<Node>list=new ArrayList<Node>();

            if(n.left!=null)
            {
                list.addAll(afterIterator(n.left));
            }
            
            if(n.right!=null)
            {
                list.addAll(afterIterator(n.right));
            }
            
            list.add(n);
            
            return list;
        }
}
