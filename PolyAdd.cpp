#include<iostream>
using namespace std;

/*��д���㷨֧��һԪ���ζ���ʽ�ļӷ�
  ��������ʵ��һԪ���ζ���ʽ�Ĵ洢
  ��struct�����ָ����������ķ�װ
  �ο���http://blog.csdn.net/wwj_748/article/details/6895844
  */

	typedef struct Node{
		int co;
		int exp;

		struct Node* next;
	}Node,*Linklist;

	Linklist create(){
		Linklist head;		//ԭ��˵ʹ��β�彨��
		Linklist s,p;
		int c,e;			//���ں�����ȡ����ʱ��������Ľڵ�
		head=new Node;
		head->next=NULL;
		cout<<"��ֱ��������ʽ��ϵ����ָ����99����"<<endl;
		cin>>c>>e;
		while(c!=99&&e!=99){
			//�������Ƕ�ȡ���ݽ��������ʱ��
			s=new Node;
			s->co=c;
			s->exp=e;
			p=head;			//�����������ҵ��������������
			while(p->next!=NULL){
				p=p->next;		//�ҵ������β�ڵ�
			}
			p->next=s;
			s->next=NULL;
			cout<<"��ֱ��������ʽ��ϵ����ָ����#����"<<endl;      //�����µĺ�׺�ڵ�
			cin>>c>>e;
		}
		return head;     //���������ͷ�ڵ㣬����ʾ��������
	};
	void display(Linklist head){    //������ʾ����ľ�����Ϣ���������ڣ��򷵻ز�ͬ��Ϣ
		if(head==NULL){
			cout<<"����ʽ��������"<<endl;
		}       //����ʽ����
		Linklist p;
		p=head->next;
		while(p){
			if(p->co>0){              //���ϵ���Ƿ�Ϊ������������
				cout<<p->co<<"x^"<<p->exp;
			}else {
				cout<<"("<<p->co<<")"<<p->exp;
			}
			if(p->next)
				cout<<"+";
			p=p->next;           //ת����һ������ʽ�ڵ�
		}
		cout<<endl<<endl;
	}

	Linklist add(Linklist a,Linklist b){
		Linklist c=new Node;
		c->next=NULL;                  //��ʼ���µ�����ͷ�ڵ�
		Node* p1=a->next;			   //������������������ʵ�־���Ĳ��ֽڵ��жϣ����
		Node* p2=b->next;
		Node* p3;
		Node* rearC=c;                //rearC��ʵ��˳����Ĳ�������ʹ��ԭ����c�������������ķ���
		if(p1!=NULL&&p2!=NULL){
			if(p1->exp<p2->exp){
			p3=new Node;
			p3->co=p1->co;
			p3->exp=p1->exp;
			p3->next=NULL;
			rearC->next=p3;           //��ӽڵ�p3���µ�������
			rearC=p3;                 //���²����������´���ӽڵ�
			//p1�Ѿ�����ӵ��µ���������˳������a���²���
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
				else{      //��ʱϵ�����
					//���ж�ϵ�����Ƿ�Ϊ0
					if((p1->co+p2->co)!=0){
						p3=new Node;
						p3->exp=p1->exp;
						p3->co=p1->co+p2->co;
						p3->next=NULL;

						rearC->next=p3;
						rearC=p3;
					}
					p1=p1->next;       //�����Ƿ�ϵ��Ϊ0������ִ�У�����������
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
		cout<<"���������ʽA"<<endl;
		Node* A;
		A=create();
		cout<<"����ʽA=";
		display(A);

		cout<<"���������ʽB";
		Node* B;
		B=create();
		cout<<"����ʽB=";
		display(B);

		cout<<"����ʽA+B=";
		Linklist C;
		C=add(A,B);
		display(C);
		getchar();
		getchar();
		return 0;
	}
	