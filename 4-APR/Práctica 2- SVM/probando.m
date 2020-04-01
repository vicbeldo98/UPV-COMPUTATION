function [] = probando(X,xl,Y,yl)
res = svmtrain(xl, X, '-t 0 -c 1 -q');
trainlabels = svmpredict(yl,Y, res,' ');

err=mean(trainlabels!=yl)

epsilon = 1.96 * sqrt(err*(1-err)/rows(Y))
disp("Para k=0 y c=1 el upper error y lower error son respectivamente:");
intUpper = err + epsilon
intLower = err - epsilon

res = svmtrain(xl, X, '-t 1 -c 1 -q');
trainlabels = svmpredict(yl,Y, res,' ');

err=mean(trainlabels!=yl)

epsilon = 1.96 * sqrt(err*(1-err)/rows(Y))
disp("Para k=1 y c=1 el upper error y lower error son respectivamente:");
intUpper = err + epsilon
intLower = err - epsilon

res = svmtrain(xl, X, '-t 2 -c 1 -q');
trainlabels = svmpredict(yl,Y, res,' ');

err=mean(trainlabels!=yl)

epsilon = 1.96 * sqrt(err*(1-err)/rows(Y))
disp("Para k=2 y c=1 el upper error y lower error son respectivamente:");
intUpper = err + epsilon
intLower = err - epsilon

res = svmtrain(xl, X, '-t 3 -c 1 -q');
trainlabels = svmpredict(yl,Y, res,' ');

err=mean(trainlabels!=yl)

epsilon = 1.96 * sqrt(err*(1-err)/rows(Y))
disp("Para k=3 y c=1 el upper error y lower error son respectivamente:");
intUpper = err + epsilon
intLower = err - epsilon
endfunction