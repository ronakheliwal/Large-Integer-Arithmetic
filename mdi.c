#include<stdio.h>
#define MAX 10000
#define B 10
#define MAX1 101

typedef struct{
    int n_digits;
    char dig[MAX];
} mdi; 
// read_mdi
  int read_mdi(mdi *n){
    int i=0;int k=0;
    char ch,temp[MAX];
    while(1){
    scanf("%c",&ch);
    if((int)ch<48 || (int)ch>57) {n->dig[i]='\0'; break;}
    temp[i]=ch;
    i++;
  }
  n->n_digits=i;
  for(i=(n->n_digits-1);i>=0;i--){
    n->dig[i]=temp[k++];
  }
  
  return 1;
  }
  
  
// print_mdi
  int print_mdi(mdi n){
    int i;
    for(i=(n.n_digits-1);i>=0;i--){
    printf("%c",n.dig[i]);
    }
    printf("\n");
    return 1;
  }
  
  void mdi_set(mdi *dst, mdi *src){
    int i;
    dst->n_digits=src->n_digits;
  for(i=(src->n_digits-1);i>=0;i--){
    dst->dig[i]=src->dig[i];
  }
    return;
  }  
  
  
//void mdi_set_int(mdi dst, int src);
void mdi_set_int(mdi *dst, int src){
  int count=0;
  int k=0;
  int i;
  //char temp[MAX];
  char ch[10]={'0','1','2','3','4','5','6','7','8','9'};
   while(src){
    i=src%10;
    dst->dig[count]=ch[i];
    src=src/10;
    count++;
  }
  dst->n_digits=count;
  
}


//*//                       void mdi_add(mdi dst, mdi src1, mdi src2)  // dst <-- src1 + src2
void mdi_add(mdi *dst, mdi *src1, mdi *src2){
  int n;
  int i;
  int val;
  if((src1->n_digits)>(src2->n_digits)) {
    n=src1->n_digits;
    for(i=src2->n_digits;i<n;i++)
      src2->dig[i]=0+'0';
  }
  else {
    n=src2->n_digits;
    for(i=src1->n_digits;i<n;i++)
      src1->dig[i]=0+'0';
  }
  int c=0;
  for(i=0;i<n;i++){
    val=(src1->dig[i]-'0'+src2->dig[i]-'0'+c);
    dst->dig[i]=val%B + '0';
    if(val>=B) c=1;
    else c=0;
	//c=val/10;
  }
  if(c==0)  dst->n_digits=n;
  else dst->n_digits=n+1;
  dst->dig[n]=1+'0';
 

}                // */


//              void mdi_sub(mdi dst, mdi src1, mdi src2); // dst <-- src1 - src2
  void mdi_sub(mdi *dst, mdi *src1, mdi *src2){
    int n;
    int i;
    int val;
    if((src1->n_digits)>(src2->n_digits)) {
      n=src1->n_digits;
      for(i=src2->n_digits;i<n;i++)
	src2->dig[i]=0+'0';
      }
    else {
      n=src2->n_digits;
      for(i=src1->n_digits;i<n;i++)
      src1->dig[i]=0+'0';
    }
    int c=0;
    int temp;
    for(i=0;i<n;i++){
      val=(src1->dig[i]-'0' - src2->dig[i]+'0'+c);
      if(val<0) temp=-val;
      else temp = val;
      if(val<0) dst->dig[i]=B-temp + '0';
      else dst->dig[i]=temp%B + '0';
      if(val <0) c=-1;
      else c=0;
    }
    if(c==0)  dst->n_digits=n;
    else dst->n_digits=n+1;
    dst->dig[n]='-';
  }


//            void mdi_mul(mdi dst, mdi src1, mdi src2); // dst <-- src1 * src2
  
  void mdi_mul(mdi *dst, mdi *src1, mdi *src2){
    int k=src1->n_digits;
    int l=src2->n_digits;
    int w[MAX];
    int i;
    int j;
    int val;
    int c=0;
   // int c2=0;
    for(i=0;i<k+l-1;i++) w[i]=0;
    
    for(i=0;i<l;i++){
      c=0;
      for(j=0;j<k;j++){
	val=w[i+j]+ (src1->dig[j]-'0')*(src2->dig[i]-'0') +c;
	w[i+j]=val%B;
	c=val/B;
      }
      w[i+k]=c;
    }
    if(w[k+l-1]>0) dst->n_digits=k+l;
    else dst->n_digits=k+l-1;
    
    for(i=0;i<dst->n_digits;i++){
      dst->dig[i]=w[i] + '0';
    }
  }
  
  int main(){
 int f1,N;
  int i;
  mdi m,x;
mdi n[MAX1],sum;
printf(" ====================================   Sum of n mdi data  ====================================================================================\n");
printf("Enter the no.(<=100) of mdi data you want to calculate the sum of : ");
scanf("%d",&N);
//printf("%d\n",N);
//return 0;
//char ch;
//scanf("%c",ch);
for(i=0;i<N+1;i++){
if(i>0) printf("Enter the %dth mdi data : ",i);
  read_mdi(&n[i]);
}

 // return 0;
for(i=0;i<N+1;i++){
 if(i>0) printf("Printing the %dth mdi data: ",i);
  print_mdi(n[i]);

}

mdi_set_int(&sum,0);
for(i=0;i<N+1;i++){
	mdi_add(&sum,&n[i],&sum);
}
printf("\nSum of %d mdi data is :",N);
print_mdi(sum);
 
printf("\n ====================================  Computation of Factorial (up to 1000!) ==================================================================\n");
  printf("enter n to compute n! :");
  scanf("%d",&f1);
  
  mdi_set_int(&m,f1);
  for(i=1;i<=f1;i++){
    mdi_set_int(&x,i);
    mdi_mul(&m,&m,&x);
  }
  printf("%d! fact is : ",f1);
  print_mdi(m);
  
  printf("\n ====================================  Computation of 2^n (up to 2^10000) ====================================================================\n");
  printf("Enter n to calulate 2^n : ");
  scanf("%d",&f1);
  mdi_set_int(&x,2);
  mdi_set_int(&m,1);
  for(i=0;i<f1;i++){
    mdi_mul(&m,&m,&x);
  }
  printf("2^%d! is : ",f1);
  print_mdi(m);
return 0;

}
  
