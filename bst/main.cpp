
typedef struct Tree //构建一个结构存放数组，假设左分支总是小于另两个数据，而右分支则大于
{
    int data;
    struct Tree *lroot; //左分支
    struct Tree *rroot; //右分支
}tree;

//新建节点
tree *add(int data)
{
    tree *infor=new tree;
    infor->data=data;
    infor->lroot=NULL;
    infor->rroot=NULL;
    return infor;
}

//要插入节点
int insert(tree *point,tree *present)
//point：是要插入的节点，present：是当前所查找到的位置
{
    tree *root; //用来指向当前位置的分支
    //如果插入的点的数据比当天前位置的数据大则指向右分支
    if(point->data>present->data)
    {
        //判断分支是否为空，若为空则插入数据且结束
        root=present->rroot;
        if(root==NULL)
        {
            present->rroot=point;
            return 0;
        }
    }
    
    //否则则指向左分支
    else
    {
        //判断分支是否为空，若为空则插入数据且结束
        root=present->lroot;
        if(root==NULL)
        {
            present->lroot=point;
            return 0;
        }
    }
    
    //如果分支不为空，则继续递归查找
    insert(point,root);
}

//由于左分支的数据总是比另两个数据小，因此只需要一直往左走，直到尽头，再往右走就能顺序读出数组
int prin(tree *present) //当前查找到的位置
{
    if(present==0)
        return 0;
    
    if(present->lroot) //先找左分支
        prin(present->lroot);
    cout<<present->data<<' '; //输出数据
    
    //找右分支
    if(present->rroot)
        prin(present->root);
}
