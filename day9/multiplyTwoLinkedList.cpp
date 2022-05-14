// find first number then 2nd number 
// then multiply
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  long long mod=1e9+7;
  long long num1=0;
  long long num2=0;
  Node* p1=l1;
  Node* p2=l2;
  while(p1){
      num1=((num1*10)%mod +p1->data)%mod;
      p1=p1->next;
  }
  while(p2){
      num2=((num2*10)%mod +p2->data)%mod;
      p2=p2->next;
  }
  return (num1*num2)%mod;
}