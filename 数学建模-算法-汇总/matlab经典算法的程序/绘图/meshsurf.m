clear
clc
x=-2:0.1:2;
[x,y]=meshgrid(x,x); %x和y都是401x401的矩阵   x是y的转置 正好是x的数量的方阵
r=sqrt(x.^2+x.^2)%+eps;
z=sinc(r);
subplot(2,1,1);
mesh(z);
subplot(2,1,2);
surf(z);
