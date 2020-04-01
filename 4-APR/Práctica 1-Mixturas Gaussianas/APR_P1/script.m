#!/usr/bin/octave -qf
function [] = script(X,xl,Y,yl)
alpha=0.9;
[m W]=pca(X);
XR = (W(:,1:30)'*(X-m)')';
YR = (W(:,1:30)'*(Y-m)')';
resultados=[]
for i=1:10
terr=mixgaussian2(XR,xl,YR,yl,i,alpha);
resultados=[resultados terr];
printf("# Componentes: %1.f Error: %5.2f\n",i,terr);
endfor

plot([1:1:10],resultados,'-o');
axis([1,10]);
refresh()
print -djpg pca_mixgaussian.jpg
input("Input to continue: ");
