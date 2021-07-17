t=-10:1:10;     %这就 是一组数据在不同的标准下的图像表示，相当吓人的。相差这么多。
subplot(2,2,1);
bar(t,cos(t));
subplot(2,2,2);
compass(t,cos(t));
subplot(2,2,3);
rose(t,cos(t));
subplot(2,2,4);
fill(t,cos(t),'b');
