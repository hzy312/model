function [a,b]=foo(x,y)
if nargout==0
elseif nargout==1
    a=x;
elseif nargout==2
    a=x;b=y;
end