
extern int bushu; 
//将n个圆盘从x柱子借助y柱子移动到z柱子上
void move(int n,char x,char y,char z){
if(n == 1){
  printf("圆盘编号%d：从%c移动到%c\n",n,x,z);
}else{
  move(n-1,x,z,y);
  printf("圆盘编号%d：从%c移动到%c\n",n,x,z);
  move(n-1,y,x,z);
}
bushu++;
}
