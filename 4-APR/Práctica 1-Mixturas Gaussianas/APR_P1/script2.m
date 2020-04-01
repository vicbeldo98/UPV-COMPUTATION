#!/usr/bin/octave -qf
function [] = script2(X,xl,Y,yl)
alpha=0.9;
[m W]=pca(X);
resultadosfinales=[];
for dim=15:15:75
  XR = (W(:,1:dim)'*(X-m)')';
  YR = (W(:,1:dim)'*(Y-m)')';
  resultados=[];
  for i=[5,10,15,20,21,22,23]
  terr=mixgaussian(XR,xl,YR,yl,i,alpha);
  resultados=[resultados terr];
  printf("# Componentes: %1.f Error: %5.2f\n",i,terr);
endfor
resultadosfinales=[resultadosfinales; resultados];
endfor

plot([5,10,15,20,21,22,23],resultadosfinales,'-o');
axis([5,23]);
h = legend({"pca=15"}, "pca=30", "pca=45", "pca=60");
legend(h, "location", "northeastoutside");
refresh()
print -djpg pca_combinations_mixgaussian.jpg
input("Input to continue: ");