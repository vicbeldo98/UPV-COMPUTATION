%Cargamos los datos
load("data/t10k-images-idx3-ubyte.mat.gz");
load("data/t10k-labels-idx1-ubyte.mat.gz");
load("data/train-images-idx3-ubyte.mat.gz");
load("data/train-labels-idx1-ubyte.mat.gz");
clases=rows(unique(xl));
[m W]=pca(X);
resultados=[];
%De 10 a 50 dimensiones
for dim=40:10:40
  XR = (W(:,1:dim)'*(X-m)')';
  YR = (W(:,1:dim)'*(Y-m)')';
  %Numero de capas
  for capas=[1]
  %Neuronas por capa
  for j=[2 4 8 16 32]
		#no quiero que haga este último caso porque seguro tardara una animalada
		if(j!=32 || capas==1)
      err =nnexp(XR,xl+1,YR,yl+1,j,clases,capas);
      epsilon = 1.96 * sqrt(err*(1-err)/rows(Y));
	  printf("Proyeccion a PCA\t\t\t Neuronas en la capa oculta\t\t\t Numero capas ocultas\t\t\t Error \t\t +- Epislon\n");
	  printf("%d------%d------%d-------%.3f--------%.3f\n",dim,j,capas,err,epsilon);
	  endif
  endfor
 endfor
endfor
