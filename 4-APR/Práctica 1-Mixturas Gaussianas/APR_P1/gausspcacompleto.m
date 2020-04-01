function []=gausspcacompleto(X,xl,Y,yl)

[m W]=pca(X);
D=columns(X);

listaerror = []

for i=10:10:100
  Xd=X-m;
  Xd=W(:,[1:i])'*Xd';
  Yd=Y-m;
  Yd=W(:,[1:i])'*Yd';
  error01=gaussian(Xd',xl,Yd',yl,0.1);
  error02=gaussian(Xd',xl,Yd',yl,0.2);
  error05=gaussian(Xd',xl,Yd',yl,0.5);
  error09=gaussian(Xd',xl,Yd',yl,0.9);
  error095=gaussian(Xd',xl,Yd',yl,0.95);
  error099=gaussian(Xd',xl,Yd',yl,0.99);
  error=gaussian(Xd',xl,Yd',yl,1.0);
  listaerror = [listaerror; error01 error02 error05 error09 error095 error099 error];
end

plot([10:10:100],listaerror,'-o');
axis([0,110]);
h = legend({"alpha=0.1"}, "alpha=0.2", "alpha=0.5", "alpha=0.9", "alpha=0.95", "alpha=0.99", "alpha=1.0");
legend(h, "location", "northeastoutside");
refresh()
print -djpg pca_graph.jpg
input("Input to continue: ");