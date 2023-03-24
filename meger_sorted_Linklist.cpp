#include<iostream>
using namespace std;
// 华为OD，技术面，合并两个有序链表，自行处理输入输出，ACM模式。
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(), next(nullptr){}
  ListNode(int x) : val(x) ,next(nullptr){}
  ListNode(int x, ListNode *node) : val(x), next(node){} 
};

//打印链表
void print_ListNode(ListNode* list){
    ListNode *p = list;
    while (p != nullptr){
      cout<< p->val << endl;
      p = p->next;
    }
    cout <<endl;
}

//测试链表节点构造
void node_test(){
  ListNode *L0 = new ListNode(5);
  cout << L0->val <<" " <<L0->next<<endl;

  ListNode *L1 = new ListNode(1);
  ListNode *L2 = new ListNode(2);
  ListNode *L3 = new ListNode(3);
  ListNode *L4 = new ListNode(4);
  L0->next = L1;
  L1->next = L2;
  L2->next = L3;
  L3->next = L4;
  print_ListNode(L0);
}

ListNode* meger_sorted_list(ListNode *p , ListNode *q){
  //创建新链表的头节点
  ListNode *dummyHead = new ListNode(-1);
  ListNode *cur = dummyHead;
  if(p == nullptr) return q;
  if(q == nullptr) return p;

  //对两个有序的链表p，q；从头依次进行遍历：比对大小，取出交小的加入cur->e
  while(p != nullptr && q != nullptr){
    //compare
    if(p->val > q->val){
      cur->next = q;
      q = q->next;
    }
    else{ //p->val < q->val
      cur->next =p;
      p = p->next;
    }
    cur = cur->next;
  }
  //如果其中一条已经遍历完毕：把另一个剩余的加到后面行
  if(p != nullptr) cur->next = p;
  if(q != nullptr) cur->next = q;

  return dummyHead->next;  //返回新链表的头结点
}

int main(){
  //测试打印链表
  // node_test();

  //构造链表1：  q->q1->q2 
  ListNode *q = new ListNode(1);
  ListNode *q1 = new ListNode(4);
  ListNode *q2 = new ListNode(5);
  q->next = q1;
  q1->next = q2;
  //print_ListNode(q);  //测试链表1

  //构造链表2： p->p1->p2
  ListNode *p = new ListNode(0);
  ListNode *p1 = new ListNode(2);
  ListNode *p2 = new ListNode(10);
  p->next = p1;
  p1->next = p2;
  // print_ListNode(p); //测试链表2
  //
  ListNode *head; //用于接收合并后的两个链表
  head = meger_sorted_list(p,q);
  print_ListNode(head);

  return 0;
}

