t=-10:1:10;     %��� ��һ�������ڲ�ͬ�ı�׼�µ�ͼ���ʾ���൱���˵ġ������ô�ࡣ
subplot(2,2,1);
bar(t,cos(t));
subplot(2,2,2);
compass(t,cos(t));
subplot(2,2,3);
rose(t,cos(t));
subplot(2,2,4);
fill(t,cos(t),'b');
