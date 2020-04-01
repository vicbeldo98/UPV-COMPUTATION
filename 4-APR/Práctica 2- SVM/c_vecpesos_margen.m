%sep es un parametro para indicar si es linealmente separable
%sep=1 si es linealmente separable y sep=0 si no lo es
function [pesos, umbral, margen, tolerancia] = c_vecpesos_margen(tr,trlabels,sep)
  C=9999;
  res = svmtrain(trlabels, tr, '-t 0 -c 9999');

  pesos = tr(res.sv_indices,:)' * res.sv_coef;
  
  %pesos es una fila de 2
  %muestras por lineas con dimensiones 2
  i=1;
  while(abs(res.sv_coef(i)) >= C)
    i=i+1;
  endwhile
  signos=sign(res.sv_coef);
  umbral =signos(i) - pesos' * tr(res.sv_indices(i),:)';
  margen = 2/norm(pesos);
  tolerancia = [];
  indices_malos = [];
  indices_buenos = [];
  indicesC = [];
  if(sep==0)
    indices_vectores=res.sv_indices;
    vecsop=tr(indices_vectores,:);
    aux = (pesos' * tr(res.sv_indices,:)' + umbral);
    k=columns(aux);
    for j=1:k
      tolerancia=[tolerancia 1-(signos(j)*aux(j))];
    endfor
    indicesC = abs(res.sv_coef());
    indices_malos=find(abs(res.sv_coef())==C);
    indices_buenos=find(abs(res.sv_coef())!=C);
  endif
  
  %Tenemos los pesos
  %Tenemos umbral
  linea=[];
  lineap=[];
  linean=[];
  disp("Parametros de la frontera");
  disp(-pesos(1)/pesos(2));
  disp((-umbral/pesos(2)));
  for x=0:7
    
    y=-(pesos(1)/pesos(2))*x - (umbral/pesos(2));
    linea=[linea y];
    y=-(pesos(1)/pesos(2))*x - ((umbral-1)/pesos(2));
    linean=[linean y];
    y=-(pesos(1)/pesos(2))*x - ((umbral+1)/pesos(2));
    lineap=[lineap y];
  endfor
  
  if(sep==1)
    plot(0:7,linea,"r",
    0:7,linean,"b",
    0:7,lineap,"c",
    tr(trlabels==1,1),tr(trlabels==1,2),"rs", tr(trlabels==2,1),tr(trlabels==2,2),"bo",
    tr(res.sv_indices(),1),tr(res.sv_indices(),2),"k+","markersize", 10
    );
  endif
  if(sep==0)
    disp("Vectores malos");
    res.sv_indices(indices_malos)
    
    plot(0:7,linea,"r",
    0:7,linean,"b",
    0:7,lineap,"c",
    tr(trlabels==1,1),tr(trlabels==1,2),"rs", tr(trlabels==2,1),tr(trlabels==2,2),"bo",
    tr(res.sv_indices(indices_malos),1),tr(res.sv_indices(indices_malos),2),"kx","markersize", 10,
    tr(res.sv_indices(indices_buenos),1),tr(res.sv_indices(indices_buenos),2),"k+","markersize", 10
    );
  endif





  
  %plot(0:7,linea);
  
  %tr(trlabels(res.sv_indices)==1,1),tr(trlabels(res.sv_indices)==1,2),"k*",
  %tr(trlabels(res.sv_indices)==2,1),tr(trlabels(res.sv_indices)==2,2),"k*"
  
  axis([0,7]);
  refresh();
  hold on;  