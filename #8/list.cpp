#include <cstdio>

class list{
public:
  list();
  bool empty();
  int size();
  void add(int k, int x);
  int get(int k);
  void remove(int k);

private:
  struct node{
    int data;
    node *next;
  };

  typedef struct node *nodePtr;

  nodePtr head;
};

list::list(){
  head = nullptr;
}

bool list::empty(){
  return head == nullptr;
}

int list::size(){
  int size = 0;
  nodePtr n = head;

  while(n != nullptr){
    n = n->next;
    size++;
  }

  return size;
}

void list::add(int k, int x){
  int i;
  nodePtr temp1 = new node;
  nodePtr temp2 = new node;

  temp1->data = x;
  temp1->next = nullptr;

  if(k == 1){
    temp1->next = head;
    head = temp1;
  }else{
    temp2 = head;
    for(i=0;i<k-2;i++){
      temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
  }

  return;
}

int list::get(int k){
  int i, x;
  nodePtr n = head;

  for(i=1;i<k;i++){
    n = n->next;
  }

  x = n->data;

  return x;
}

void list::remove(int k){
  int i;
  nodePtr n = head;
  nodePtr temp;

  if(k == 1){
    temp = head;
    head = temp->next;
    delete temp;
    return;
  }

  for(i=0;i<k-2;i++){
    n = n->next;
  }

  temp = n->next;
  n->next = temp->next;
  delete temp;

  return;
}

int main(){
  int N, M, i, k, x;
  list myList;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d %d",&k,&x);
    myList.add(k,x);
  }

  scanf("%d",&M);

  for(i=0;i<M;i++){
    scanf("%d",&k);
    myList.remove(k);
  }

  scanf("%d",&k);

  printf("%d %d\n",myList.size(), myList.get(k));

  return 0;
}
