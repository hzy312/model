function theImage=gasket(numPoints)
theImage =zeros(1000,1000);
corners=[866 1;1 500;866 1000];
startPoint=[866 1];
theRand=rand(numPoints,1);
theRand=ceil(theRand*3);
for i=1:numPoints
    startPoint=floor((corners(theRand(i),:)+startPoint)/2);
    theImage(startPoint(1),startPoint(2))=1;
end