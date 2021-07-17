function r=mrank(n)
r=zeros(n,1);
for k=1:n
    r(k)=rank(magic(k));
end