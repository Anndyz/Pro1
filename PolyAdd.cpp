#include<iostream>
using namespace std;

/*试写出算法支持一元二次多项式的加法
  用链表来实现一元二次多项式的存储
  用struct来完成指针域数据域的封装
  参考：http://blog.csdn.net/wwj_748/article/details/6895844
  */

	typedef struct Node{
		int co;
		int exp;

		struct Node* next;
	}Node,*Linklist;

	Linklist create(){
		Linklist head;		//原文说使用尾插建表法
		Linklist s,p;
		int c,e;			//用于后续读取数据时插入链表的节点
		head=new Node;
		head->next=NULL;
		cout<<"请分别输入多项式的系数与指数以99结束"<<endl;
		cin>>c>>e;
		while(c!=99&&e!=99){
			//接下来是读取数据建立链表的时候
			s=new Node;
			s->co=c;
			s->exp=e;
			p=head;			//用于来迭代找到具体的链表数据
			while(p->next!=NULL){
				p=p->next;		//找到具体的尾节点
			}
			p->next=s;
			s->next=NULL;
			cout<<"请分别输入多项式的系数与指数以#结束"<<endl;      //建立新的后缀节点
			cin>>c>>e;
		}
		return head;     //返回链表的头节点，来表示整个链表
	};
	void display(Linklist head){    //用来显示链表的具体信息，若不存在，则返回不同信息
		if(head==NULL){
			cout<<"多项式并不存在"<<endl;
		}       //多项式存在
		Linklist p;
		p=head->next;
		while(p){
			if(p->co>0){              //针对系数是否为负来加载括号
				cout<<p->co<<"x^"<<p->exp;
			}else {
				cout<<"("<<p->co<<")"<<p->exp;
			}
			if(p->next)
				cout<<"+";
			p=p->next;           //转到下一个多项式节点
		}
		cout<<endl<<endl;
	}

	Linklist add(Linklist a,Linklist b){
		Linklist c=new Node;
		c->next=NULL;                  //初始化新的链表头节点
		Node* p1=a->next;			   //用来遍历整个链表来实现具体的部分节点判断，相加
		Node* p2=b->next;
		Node* p3;
		Node* rearC=c;                //rearC来实现顺链表的操作，而使用原来的c链表来完成链表的返回
		if(p1!=NULL&&p2!=NULL){
			if(p1->exp<p2->exp){
			p3=new Node;
			p3->co=p1->co;
			p3->exp=p1->exp;
			p3->next=NULL;
			rearC->next=p3;           //添加节点p3到新的链表中
			rearC=p3;                 //更新操作，便于下次添加节点
			//p1已经被添加到新的链表，于是顺着链表a向下操作
			p1=p1->next;
			}else 
				if(p1->exp>p2->exp){
				p3=new Node;
				p3->co=p2->co;
				p3->exp=p2->exp;
				p3->next=NULL;
				rearC->next=p3;
				rearC=p3;
				p2=p2->next;
			}
				else{      //此时系数相等
					//先判断系数和是否为0
					if((p1->co+p2->co)!=0){
						p3=new Node;
						p3->exp=p1->exp;
						p3->co=p1->co+p2->co;
						p3->next=NULL;

						rearC->next=p3;
						rearC=p3;
					}
					p1=p1->next;       //无论是否系数为0都必须执行，放置在外面
					p2=p2->next;
				}
		  }

		if(p1==NULL){
			while(p2!=NULL){
				p3=new Node;
				p3->co=p2->co;
				p3->exp=p2->exp;
				p3->next=NULL;
				rearC->next=p3;
				rearC=p3;
				p2=p2->next;
			}
		}
		else {
			while(p1!=NULL){
			    p3=new Node;
				p3->co=p1->co;
				p3->exp=p1->exp;
				p3->next=NULL;
				rearC->next=p3;
				rearC=p3;
				p1=p1->next;
			}
		}
		return c;
	}

	int main(){
		cout<<"请输入多项式A"<<endl;
		Node* A;
		A=create();
		cout<<"多项式A=";
		display(A);

		cout<<"请输入多项式B";
		Node* B;
		B=create();
		cout<<"多项式B=";
		display(B);

		cout<<"多项式A+B=";
		Linklist C;
		C=add(A,B);
		display(C);
		getchar();
		getchar();
		return 0;
	}
	