function []=gausspcasuavizado1(X,xl,Y,yl,alp)

[m W]=pca(X);
D=columns(X);

listaerror = []

for i=10:10:100
  Xd=X-m;
  Xd=W(:,[1:i])'*Xd';
  Yd=Y-m;
  Yd=W(:,[1:i])'*Yd';
  error=gaussian(Xd',xl,Yd',yl,1.0);
  #listaerror05 = [listaerror05 error05];
  listaerror = [listaerror; error];
  
end

#listaerror = [listaerror; listaerror05]'

plot([10:10:100],listaerror,'o-r');
axis([0,110]);
h = legend({"alpha=0.1"}, "alpha=0.2", "alpha=0.5", "alpha=0.9", "alpha=0.95", "alpha=0.99", "alpha=1.0");
legend(h, "location", "northeastoutside");
refresh()
print -djpg gauss_pca_suavizado1_graph.jpg
input("Input to continue: ");